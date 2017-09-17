#ifndef TWITTERCLIENT_H
#define TWITTERCLIENT_H

#include <QObject>

class QNetworkAccessManager;

class TwitterClient : public QObject
{
    Q_OBJECT
public:
    explicit TwitterClient(QObject *parent = nullptr);

    void fetchAuthorizationToken();
    void fetchTweetsForUser();
    void fetchImageAtURL();

signals:

public slots:

private:
    QNetworkAccessManager *manager;
};

#endif // TWITTERCLIENT_H
