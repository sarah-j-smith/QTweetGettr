#include "tweetrow.h"
#include "ui_tweetrow.h"

TweetRow::TweetRow() :
    QTableWidgetItem(QTableWidgetItem::UserType + 1),
    ui(new Ui::TweetRow)
{
    ui->setupUi(this);
}

TweetRow::~TweetRow()
{
    delete ui;
}
