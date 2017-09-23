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
        if (imageReply->error() == QNetworkReply::NoError)
        {
            auto image = QImage(imageReply->readAll());
            label->setPixmap(QPixmap::fromImage(image));
        }
    });
}
