#ifndef TWITTERAUTHORIZATION_H
#define TWITTERAUTHORIZATION_H

#include <QString>

class TwitterAuthorization
{
public:
    static QByteArray token();
    static void setToken(const QString &token);

    static bool hasToken();
};

#endif // TWITTERAUTHORIZATION_H
