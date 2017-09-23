#ifndef TWEETPRIVATE_H
#define TWEETPRIVATE_H

#include <QJsonObject>
#include <QImage>

#include <functional>

class TweetPrivate
{
public:
    QString text;
    QString createdAt;
    QString name;
    QString screenName;
    QString description;
    QImage userImage;
    QString profileImageURL;

    std::function<QString ()> biggerProfileImageURL;
    std::function<QString ()> originalProfileURL;

    QJsonObject tweetDictionary;

    QJsonObject user() const
    {
        return tweetDictionary["user"].toObject();
    }
};

#endif // TWEETPRIVATE_H
