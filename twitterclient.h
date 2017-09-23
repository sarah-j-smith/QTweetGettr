#ifndef TWITTERCLIENT_H
#define TWITTERCLIENT_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>

#include <functional>
#include <memory>

class Tweet;

class TwitterClient
{
public:
    TwitterClient();

    void fetchAuthorizationToken(std::function<void (QString)> completion);
    void fetchTweetsForUser(const QString &user, std::function<void (std::vector<Tweet>, QString)> completion);
    void fetchImageAtURL(const QString &imageURL, std::function<void (QImage)> completion);

    static QUrl createURL(const QString &urlString);

    TwitterClient(const TwitterClient &) = delete;
    TwitterClient &operator=(const TwitterClient &) = delete;

    TwitterClient(const TwitterClient &&) = delete;
    TwitterClient &operator=(const TwitterClient &&) = delete;

signals:

public slots:

private:
    std::unique_ptr<QNetworkAccessManager> manager;
};

#endif // TWITTERCLIENT_H
