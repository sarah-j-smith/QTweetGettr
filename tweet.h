#ifndef TWEET_H
#define TWEET_H

#include <vector>
#include <unordered_map>

#include <QObject>
#include <QJsonArray>
#include <QImage>

class TweetPrivate;

class Tweet: QObject
{
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged);
    Q_PROPERTY(QString createdAt READ createdAt WRITE setCreatedAt NOTIFY createdAtChanged);
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged);
    Q_PROPERTY(QString screenName READ screenName WRITE setScreenName NOTIFY screenNameChanged);
    Q_PROPERTY(QImage userImage READ userImage WRITE setUserImage NOTIFY userImageChanged);
    Q_PROPERTY(QString profileImageURL READ profileImageURL WRITE setProfileImageURL NOTIFY profileImageURLChanged);
    Q_PROPERTY(QString biggerProfileImageURL READ biggerProfileImageURL NOTIFY biggerProfileImageURLChanged);

    Q_OBJECT
public:
    explicit Tweet(const QJsonObject &tweetData);
    virtual ~Tweet();

    Tweet(const Tweet &other): d(other.d) {  }
    Tweet & operator=(const Tweet &rhs) { d = rhs.d; return *this; };

    Tweet(const Tweet &&movedOther): d(movedOther.d) { }
    Tweet & operator =(const Tweet &&movedRhs) { d = movedRhs.d; return *this; }

    static std::vector<Tweet> tweetsFromArray(const QJsonArray &tweetData);

    QString text() const;
    void setText(const QString &newText);
    QString createdAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    QString name() const;
    void setName(const QString &newText);
    QString screenName() const;
    void setScreenName(const QString &newText);
    QImage userImage() const;
    void setUserImage(const QImage &newUserImage);
    QString profileImageURL() const;
    void setProfileImageURL(const QString &newText);
    QString biggerProfileImageURL() const;

signals:
    void textChanged(QString);
    void createdAtChanged(QString);
    void nameChanged(QString);
    void screenNameChanged(QString);
    void userImageChanged(QImage);
    void profileImageURLChanged(QString);
    void biggerProfileImageURLChanged(QString);

private:
    std::shared_ptr<TweetPrivate> d;
};

#endif // TWEET_H
