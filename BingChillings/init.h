#ifndef INIT_H
#define INIT_H

#include <QWidget>
#include "user.h"

class Init
{
public:
    Init(QVector<User> &temp);

    QVector<User> users;

    void readFromJSON();
    void validatePassword(QString &password, bool signupOrLogin);
    bool checkPassword(QString &password,User &user, bool signupOrLogin);
    QString passwordHash(QString &password);

signals:

};

#endif // INIT_H
