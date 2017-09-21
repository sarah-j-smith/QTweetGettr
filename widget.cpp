#include "widget.h"
#include "ui_widget.h"
#include "tweetrow.h"
#include "twitterclient.h"

#include <QTimer>
#include <QItemDelegate>
#include <QtDebug>

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
    twitterClient->fetchAuthorizationToken([](QString errorString){
        qDebug() << errorString;
    });
    for (int i = 0; i < 30; ++i)
    {
        auto row = qobject_cast<TweetRow *>(ui->tableWidget->cellWidget(i, 0));
        std::cout << row << std::endl;
        row->setTwitterHandle(QString("Foobar %1").arg(i));
    }
}
