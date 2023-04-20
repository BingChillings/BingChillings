#ifndef USER_H
#define USER_H

#include <QString>
#include <QDate>
#include <QJsonObject>
#include <QJsonArray>
#include <QVector>



class User
{
public:
    User( QString &firstName, QString &lastName, QDate &dateOfBirth, QString &gender, QString &profilePictureFileName, QString &username, QString &password, QVector<int> &arrayOfInts , bool hashNeeded);

    QString firstName();
    QString lastName();
    QDate dateOfBirth();
    QString gender();
    QString profilePictureFileName();
    QString username();
    QString password();
    QVector<int> scores();

    void write(QVector<User> &users);

private:

    QString firstName_;
    QString lastName_;
    QDate dateOfBirth_;
    QString gender_;
    QString profilePictureFileName_;
    QString username_;
    QString password_;
    QVector<int> scores_;
};

#endif // USER_H
