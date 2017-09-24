#include "twitterclient.h"
#include "twitterauthorization.h"
#include "tweet.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QImage>
#include <QFile>

#include <iostream>
#include <functional>
#include <memory>
#include <algorithm>

static const char *kContentTypeHeader = "Content-Type";
static const char *kAuthorizationHeaderKey = "Authorization";
static const char *kOAuthRootURL = "https://api.twitter.com/oauth2/token";
static const char *kTimelineRootURL = "https://api.twitter.com/1.1/statuses/user_timeline.json?count=30&screen_name=";
static const char *kAuthorizationBody = "grant_type=client_credentials";
static const char *kAuthorizationContentType = "application/x-www-form-urlencoded;charset=UTF-8";

/// Local helpers
///
QByteArray headerForAuthorization()
{
    auto authData = std::unique_ptr<QFile>(new QFile(":/res/TwitterCredentials.json"));
    authData->open(QIODevice::ReadOnly);
    auto json = QJsonDocument::fromJson(authData->readAll());
    auto apiKey = json.object()["APIKey"].toString();
    auto apiSecret = json.object()["APISecret"].toString();
    if (apiKey.isEmpty() || apiSecret.isEmpty())
    {
        return QByteArray();
    }
    auto bytes = (apiKey + ":" + apiSecret).toUtf8();
    return QByteArray("Basic ") + bytes.toBase64();
}

QByteArray headerWithAuthorization()
{
    return QByteArray("Bearer ") + TwitterAuthorization::token();
}

TwitterClient::TwitterClient()
    : manager(new QNetworkAccessManager)
{
    //
}

void TwitterClient::fetchAuthorizationToken(std::function<void (QString)> completion)
{
    auto authHeader = headerForAuthorization();
    if (authHeader.isEmpty())
    {
        completion("API Key & Secret not configured!");
        return;
    }
    auto tokenRequest = QNetworkRequest(QUrl(kOAuthRootURL));
    tokenRequest.setRawHeader(kContentTypeHeader, kAuthorizationContentType);
    tokenRequest.setRawHeader(kAuthorizationHeaderKey, authHeader);

    auto tokenReply = manager->post(tokenRequest, kAuthorizationBody);
    QObject::connect(tokenReply, &QNetworkReply::finished, [=]{
        auto authData = tokenReply->readAll();
        auto json = QJsonDocument::fromJson(authData);
        auto tokenString = json.object()["access_token"].toString();
        TwitterAuthorization::setToken(tokenString);
        if (TwitterAuthorization::hasToken())
        {
            completion(QString());
        }
        else
        {
            auto errorReport = tokenReply->error() == QNetworkReply::NoError ? "Could not authorize" : tokenReply->errorString();
            completion(errorReport);
        }
        inFlightRequests.erase(std::remove(inFlightRequests.begin(), inFlightRequests.end(), tokenReply));
    });
    inFlightRequests.push_back(tokenReply);
}

void TwitterClient::fetchTweetsForUser(const QString &user, std::function<void (std::vector<Tweet>, QString)> completion)
{
    auto userURL = TwitterClient::createURL(kTimelineRootURL + user.trimmed());
    auto tweetRequest = QNetworkRequest(userURL);
    tweetRequest.setRawHeader(kAuthorizationHeaderKey, headerWithAuthorization());
    auto tweetReply = manager->get(tweetRequest);
    QObject::connect(tweetReply, &QNetworkReply::finished, [=]{
        auto responseData = QJsonDocument::fromJson(tweetReply->readAll());
        if (responseData.isArray())
        {
            auto tweets = Tweet::tweetsFromArray(responseData.array());
            completion(tweets, QString());
        }
        else
        {
            auto errorReport = tweetReply->errorString().isEmpty() ? "Could not fetch tweets" : tweetReply->errorString();
            completion(std::vector<Tweet>(), errorReport);
        }
        inFlightRequests.erase(std::remove(inFlightRequests.begin(), inFlightRequests.end(), tweetReply));
    });
    inFlightRequests.push_back(tweetReply);
}

void TwitterClient::fetchImageAtURL(const QString &imageURL, std::function<void (QImage)> completion)
{
    auto imageURLRequest = QNetworkRequest(createURL(imageURL));
    auto imageReply = manager->get(imageURLRequest);
    QObject::connect(imageReply, &QNetworkReply::finished, [&]{
        auto imageData = imageReply->readAll();
        if (imageData.size() > 0)
        {
            completion(QImage(imageData));
        }
        else
        {
            completion(QImage());
        }
        inFlightRequests.erase(std::remove(inFlightRequests.begin(), inFlightRequests.end(), imageReply));
    });
    inFlightRequests.push_back(imageReply);
}

QUrl TwitterClient::createURL(const QString &urlString)
{
    auto url = QUrl(urlString);
    url.setScheme("https");
    return url;
}


