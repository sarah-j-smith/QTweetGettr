#ifndef TWEETMODEL_H
#define TWEETMODEL_H

#include <QAbstractTableModel>

class TweetModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TweetModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:

    std::vector<TweetPtr> tweets;
};

#endif // TWEETMODEL_H
