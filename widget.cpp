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
#include <QGuiApplication>
#include <QScreen>
#include <QScrollBar>

#if defined(Q_OS_IOS) || defined(Q_OS_ANDROID)
    #include <QScroller>
#endif

#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , tableIntialised(false)
    , ui(new Ui::Widget)
    , twitterClient(new TwitterClient())
{
    ui->setupUi(this);

#if defined(Q_OS_IOS) || defined(Q_OS_ANDROID)
    auto rowHeight = 44 * QGuiApplication::screens().first()->devicePixelRatio();
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(rowHeight);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QScroller *scroller = QScroller::scroller(ui->tableWidget);
    ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    QScrollerProperties properties = QScroller::scroller(scroller)->scrollerProperties();
    QVariant overshootPolicy = QVariant::fromValue<QScrollerProperties::OvershootPolicy>(QScrollerProperties::OvershootAlwaysOff);
    properties.setScrollMetric(QScrollerProperties::VerticalOvershootPolicy, overshootPolicy);
    scroller->setScrollerProperties(properties);

    //Scrolling Gesture
    scroller->grabGesture(ui->tableWidget, QScroller::LeftMouseButtonGesture);
#endif
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    loadTweets();
}

void Widget::setupTable()
{
    if (tableIntialised) { return; }
    for (int i = 0; i < 30; ++i)
    {
        auto row = new TweetRow();
        ui->tableWidget->setCellWidget(i, 0, row);
    }
    tableIntialised = true;
}

void Widget::fetchTweets()
{
    // FETCH TWEETS & APPLY THEM TO ROWS
}

void Widget::loadTweets()
{
    // GET TOKEN IF NEEDED & CALL FETCH TWEETS
}

void Widget::on_lineEdit_editingFinished()
{
    auto twitterHandle = ui->lineEdit->text().trimmed();
    ui->pushButton->setEnabled(twitterHandle.count() > 2);
}

void Widget::on_lineEdit_returnPressed()
{
    auto twitterHandle = ui->lineEdit->text().trimmed();
    if (twitterHandle.count() > 2)
    {
        loadTweets();
    }
}
