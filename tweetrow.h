#ifndef TWEETROW_H
#define TWEETROW_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class TweetRow;
}

class TweetRow : public QWidget
{
    Q_OBJECT

public:
    explicit TweetRow(QWidget *parent = 0);
    ~TweetRow();

private:
    Ui::TweetRow *ui;
};

#endif // TWEETROW_H
