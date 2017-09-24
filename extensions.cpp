#include "extensions.h"

#include <QString>
#include <QGlobalStatic>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QLabel>
#include <QImage>

Q_GLOBAL_STATIC(QNetworkAccessManager, networkManager);

void loadURLInto(const QString &url, QLabel *label)
{
    auto imageURLRequest = QNetworkRequest(url);
    auto imageReply = networkManager->get(imageURLRequest);
    QObject::connect(imageReply, &QNetworkReply::finished, [=](){
        auto image = QImage::fromData(imageReply->readAll());
        if (!image.isNull())
        {
            label->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            label->setPixmap(QPixmap::fromImage(QImage(":/res/default@2x.png")));
        }
    });
}
