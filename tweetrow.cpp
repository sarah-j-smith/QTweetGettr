#include "tweetrow.h"
#include "ui_tweetrow.h"
#include "tweet.h"
#include "extensions.h"

TweetRow::TweetRow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TweetRow)
{
    ui->setupUi(this);
}

TweetRow::~TweetRow()
{
    delete ui;
}

QString TweetRow::statusText() const
{
    return ui->statusText->text();
}

void TweetRow::setStatusText(const QString &text)
{
    ui->statusText->setText(text);
}

QString TweetRow::twitterName() const
{
    return ui->userTitle->text();
}

void TweetRow::setTwitterName(const QString &name)
{
    ui->userTitle->setText(name);
}

QString TweetRow::twitterHandle() const
{
    return ui->userHandle->text();
}

void TweetRow::setTwitterHandle(const QString &handle)
{
    ui->userHandle->setText(handle);
}

QPixmap TweetRow::profilePicture() const
{
    auto pic = ui->userIcon->pixmap();
    return QPixmap(*pic);
}

void TweetRow::setProfilePicture(const QPixmap &picture)
{
    ui->userIcon->setPixmap(picture);
}

void TweetRow::applyTweet(const Tweet &tweet)
{
    setStatusText(tweet.text());
    setTwitterName(tweet.name());
    setTwitterHandle(tweet.screenName());
    setProfilePicture(QPixmap::fromImage(tweet.userImage()));
    loadURLInto(tweet.biggerProfileImageURL(), ui->userIcon);
}
