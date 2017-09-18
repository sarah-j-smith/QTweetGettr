#include "tweetrow.h"
#include "ui_tweetrow.h"

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
