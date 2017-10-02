#include "twitterauthorization.h"

#include <QSettings>
#include <QString>

static const char *kAuthorizationTokenStorageKey = "authorizationToken";

void TwitterAuthorization::setToken(const QString &token)
{
    QSettings settings;
    settings.setValue(kAuthorizationTokenStorageKey, token);
}

QByteArray TwitterAuthorization::token()
{
    QSettings settings;
    return settings.value(kAuthorizationTokenStorageKey).toByteArray();
}

bool TwitterAuthorization::hasToken()
{
    return !token().isEmpty();
}
