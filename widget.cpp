#include "widget.h"
#include "ui_widget.h"
#include "tweetrow.h"

#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    auto self = this;
    QTimer::singleShot(0, this, [self]{ self->loadTweets(); });
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
    for (int i = 0; i < 30; ++i)
    {
        auto row = new TweetRow(self);
        ui->tableWidget->setItem(i, 0, row);
    }
}
