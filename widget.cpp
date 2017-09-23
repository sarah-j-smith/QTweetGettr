#include "widget.h"
#include "ui_widget.h"
#include "tweet.h"
#include "tweetrow.h"
#include "twitterclient.h"
#include "twitterauthorization.h"

#include <QTimer>
#include <QItemDelegate>
#include <QtDebug>
#include <QMessageBox>

#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , twitterClient(new TwitterClient())
{
    ui->setupUi(this);

    auto self = this;
    QTimer::singleShot(0, this, [=] {
        for (int i = 0; i < 30; ++i)
        {
            auto row = new TweetRow();
            self->ui->tableWidget->setCellWidget(i, 0, row);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    loadTweets();
}

void Widget::loadTweets()
{
    if (!TwitterAuthorization::hasToken())
    {
        twitterClient->fetchAuthorizationToken([](QString errorString){
            qDebug() << errorString;
        });
    }
    auto twitterHandle = ui->lineEdit->text().trimmed();
    twitterClient->fetchTweetsForUser(twitterHandle, [=](std::vector<Tweet> tweets, QString error){
        if (tweets.empty())
        {
            QMessageBox::warning(this, "Error", error.isEmpty() ? "Could not fetch tweets" :error, QMessageBox::Ok);
        }
        else
        {
            for (int i = 0; i < 30; ++i)
            {
                auto row = qobject_cast<TweetRow *>(ui->tableWidget->cellWidget(i, 0));
                row->applyTweet(tweets[i]);
            }
        }
    });
}

void Widget::on_lineEdit_editingFinished()
{
    auto twitterHandle = ui->lineEdit->text().trimmed();
    ui->pushButton->setEnabled(twitterHandle.count() > 2);
}
