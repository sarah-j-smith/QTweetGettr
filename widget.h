#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <memory>

namespace Ui {
class Widget;
}

class TwitterClient;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_returnPressed();

private:
    void setupTable();
    void loadTweets();

    Ui::Widget *ui;

    std::shared_ptr<TwitterClient> twitterClient;
};

#endif // WIDGET_H
