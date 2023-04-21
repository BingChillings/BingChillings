#ifndef INIT_H
#define INIT_H

#include <QWidget>
#include "user.h"

class Init
{
public:
    Init();

    QVector<User> users;

    void readFromJSON();

    static bool checkPassword(QString &password,User &user);
    static QString passwordHash(QString &password);

signals:

};

#endif // INIT_H
