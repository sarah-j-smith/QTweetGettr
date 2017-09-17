#include "twitterclient.h"
#include "twitterauthorization.h"

#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

// Edit these here in the source code, or inside the file TwitterCredentials.json
static const char *kAPIKey = "";
static const char *kAPISecret = "";

static const char *kPostMethod = "POST";
static const char *kGetMethod = "GET";
static const char *kContentTypeHeader = "Content-Type";
static const char *kAuthorizationHeaderKey = "Authorization";
static const char *kOAuthRootURL = "https://api.twitter.com/oauth2/token";
static const char *kTimelineRootURL = "https://api.twitter.com/1.1/statuses/user_timeline.json?count=30&screen_name=";
static const char *kAuthorizationBody = "grant_type=client_credentials";
static const char *kAuthorizationContentType = "application/x-www-form-urlencoded;charset=UTF-8";

/// Local helpers
///
QString headerForAuthorization()
{
    auto authData = std::unique_ptr<QFile>(new QFile("qrc:/res/TwitterCredentials.json"));
    auto json = QJsonDocument::fromJson(authData->readAll());
    auto apiKey = json.object()["APIKey"].toString();
    auto apiSecret = json.object()["APISecret"].toString();
    if (apiKey.isEmpty() || apiSecret.isEmpty())
    {
        return QString();
    }
    auto bytes = (apiKey + ":" + apiSecret).toUtf8();
    return QString("Basic %1").arg(QString(bytes.toBase64()));
}

QString headerWithAuthorization()
{
    return QString("Bearer %1").arg(TwitterAuthorization::token());
}

TwitterClient::TwitterClient(QObject *parent)
    : QObject(parent)
    , manager(new QNetworkAccessManager)
{
    //
}

void TwitterClient::fetchAuthorizationToken()
{

}
