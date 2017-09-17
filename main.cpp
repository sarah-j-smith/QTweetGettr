#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Smithsoft");
    QCoreApplication::setOrganizationDomain("smithsoft.com.au");
    QCoreApplication::setApplicationName("QTweetGettr");

    Widget w;
    w.show();

    return a.exec();
}
