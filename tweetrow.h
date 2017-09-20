#ifndef TWEETROW_H
#define TWEETROW_H

#include <QWidget>
#include <QPixmap>
#include <QTableWidgetItem>

namespace Ui {
class TweetRow;
}

class TweetRow : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString statusText READ statusText WRITE setStatusText NOTIFY statusTextChanged);
    Q_PROPERTY(QString twitterName READ twitterName WRITE setTwitterName NOTIFY twitterNameChanged);
    Q_PROPERTY(QString twitterHandle READ twitterHandle WRITE setTwitterHandle NOTIFY twitterHandleChanged);
    Q_PROPERTY(QPixmap profilePicture READ profilePicture WRITE setProfilePicture NOTIFY profilePictureChanged);
public:
    explicit TweetRow(QWidget *parent = 0);
    ~TweetRow();

    QString statusText() const;
    void setStatusText(const QString &text);
    QString twitterName() const;
    void setTwitterName(const QString &name);
    QString twitterHandle() const;
    void setTwitterHandle(const QString &handle);
    QPixmap profilePicture() const;
    void setProfilePicture(const QPixmap &picture);

signals:
    void statusTextChanged(QString);
    void twitterNameChanged(QString);
    void twitterHandleChanged(QString);
    void profilePictureChanged(QPixmap);

private:
    Ui::TweetRow *ui;
};

#endif // TWEETROW_H
