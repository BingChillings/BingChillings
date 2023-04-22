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
    User();
    User(QString &firstName, QString &lastName, QDate &dateOfBirth,
         QString &gender, QString &profilePictureFileName, QString &username,
         QString &password, QVector<int> &arrayOfInts);

    QString firstName();
    QString lastName();
    QDate dateOfBirth();
    QString gender();
    QString profilePictureFileName();
    QString username() const;
    QString password() const;
    QVector<int> scores();

    QJsonObject userSingleObject;
    QJsonObject userArrObj;


    void write();
//    QVector<User> read();
//    void validatePassword(QString &password);
//    void validateUsername(QString &username);
    QString passwordHash(QString &password);
    bool checkPassword(QJsonObject &userArrObj, QString &password, QString &username);
//    bool checkPassword(QString &password, User &user);
//    bool checkPassword()
//    bool checkPassword(QString &password, QString &username);


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
