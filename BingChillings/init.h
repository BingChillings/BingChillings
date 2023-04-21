#ifndef INIT_H
#define INIT_H

#include <QWidget>
#include "user.h"

class Init
{
public:
    Init();

    static QVector<User> users;

    QVector<User> readFromJSON();

    static bool checkPassword(QString &password, const User &user);
    static QString passwordHash(QString &password);

signals:

};

#endif // INIT_H
