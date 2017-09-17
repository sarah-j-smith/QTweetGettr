#ifndef TWEETROW_H
#define TWEETROW_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class TweetRow;
}

class TweetRow : public QTableWidgetItem
{
    Q_OBJECT

public:
    explicit TweetRow();
    ~TweetRow();

private:
    Ui::TweetRow *ui;
};

#endif // TWEETROW_H
