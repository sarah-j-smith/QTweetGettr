#ifndef TWITTERCLIENT_H
#define TWITTERCLIENT_H

#include <QObject>
#include <QString>

#include <functional>

class QNetworkAccessManager;
class Tweet;

class TwitterClient : public QObject
{
    Q_OBJECT
public:
    explicit TwitterClient(QObject *parent = nullptr);

    void fetchAuthorizationToken(std::function<void (QString)> completion);
    void fetchTweetsForUser(const QString &user, std::function<void (std::vector<Tweet>, QString)> completion);
    void fetchImageAtURL(const QString &imageURL, std::function<void (QImage)> completion);

    static QUrl createURL(const QString &urlString);

signals:

public slots:

private:
    QNetworkAccessManager *manager;
};

#endif // TWITTERCLIENT_H
