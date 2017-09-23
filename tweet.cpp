#include "tweet.h"
#include "tweetprivate.h"

#include <algorithm>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QImage>

Tweet::Tweet(const QJsonObject &tweetData)
    : d(new TweetPrivate)
{
    d->text = tweetData["text"].toString();
    d->createdAt = tweetData["created_at"].toString();
    d->name = d->user()["name"].toString();
    d->screenName = d->user()["screenName"].toString();
    d->description = QJsonDocument(d->tweetDictionary).toJson();
    d->userImage = QImage("qrc://res/default@2x.png");
    d->profileImageURL = d->user()["profile_image_url"].toString();
    d->biggerProfileImageURL = [=](){ return d->profileImageURL.replace("_normal", "_bigger"); };
}

Tweet::~Tweet()
{
    //
}

std::vector<Tweet> Tweet::tweetsFromArray(const QJsonArray &tweetData)
{
    auto tweets = std::vector<Tweet>();
    std::for_each(tweetData.constBegin(), tweetData.constEnd(), [&](QJsonValue val){
        tweets.push_back(Tweet(val.toObject()));
    });
    return tweets;
}

QString Tweet::text() const
{
    return d->text;
}

void Tweet::setText(const QString &newText)
{
    if (d->text != newText)
    {
        d->text = newText;
        emit textChanged(newText);
    }
}

QString Tweet::createdAt() const
{
    return d->createdAt;
}

void Tweet::setCreatedAt(const QString &newCreatedAt)
{
    if (d->createdAt != newCreatedAt)
    {
        d->createdAt = newCreatedAt;
        emit createdAtChanged(newCreatedAt);
    }
}

QString Tweet::name() const
{
    return d->name;
}

void Tweet::setName(const QString &newName)
{
    if (d->name != newName)
    {
        d->name = newName;
        emit nameChanged(newName);
    }
}

QString Tweet::screenName() const
{
    return d->screenName;
}

void Tweet::setScreenName(const QString &newScreenName)
{
    if (d->screenName != newScreenName)
    {
        d->screenName = newScreenName;
        emit screenNameChanged(newScreenName);
    }
}

QImage Tweet::userImage() const
{
    return d->userImage;
}

void Tweet::setUserImage(const QImage &newUserImage)
{
    if (d->userImage != newUserImage)
    {
        d->userImage = newUserImage;
        emit userImageChanged(newUserImage);
    }
}

QString Tweet::profileImageURL() const
{
    return d->profileImageURL;
}

void Tweet::setProfileImageURL(const QString &newProfileImageURL)
{
    if (d->profileImageURL != newProfileImageURL)
    {
        d->profileImageURL = newProfileImageURL;
        emit profileImageURLChanged(newProfileImageURL);
        auto biggerURL = biggerProfileImageURL();
        emit biggerProfileImageURLChanged(biggerURL);
    }
}

QString Tweet::biggerProfileImageURL() const
{
    return d->biggerProfileImageURL();
}
