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

<<<<<<< HEAD
    QVector<User> read();
    void write(QVector<User> &users);
    QString passwordHash(QString &password);
    void validatePassword(QString &password);
    void validateUsername(QString &username);
    bool checkPassword(QString &password, User &user);
=======
//    QVector<User> read();
    void write(QVector<User> &users);
//    QString passwordHash(QString &password);
//    void validatePassword(QString &password);
//    void validateUsername(QString &username);
////    bool checkPassword(QString &password, User &user);
//    bool checkPassword(QString &password, User &user);

>>>>>>> f8697206ff47e8f5ec59ca281a0f3a7a369703bf
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
