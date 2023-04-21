#include <QFile>
#include <QJsonDocument>
#include <QCryptographicHash>

#include "init.h"



Init::Init(QVector<User> &temp):users(temp)
{

}




void Init::readFromJSON()
{
    QFile file("users.json");
    QJsonArray jsonArray;

    if (file.open(QIODevice::ReadOnly)) {
        QByteArray fileContent = file.readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(fileContent);

        if (jsonDocument.isNull()){
            qDebug() << "Failed to parse JSON from file.";
        }

        jsonArray = jsonDocument.array();
    }
    else {
        qDebug() << "Failed to open file for reading.";
    }

    for (int i = 0; i < jsonArray.size(); ++i)
    {
        QJsonObject json = jsonArray[i].toObject();
        QString firstName = json["firstName"].toString();
        QString lastName = json["lastName"].toString();
        QDate dateOfBirth = QDate::fromString(json["dateOfBirth"].toString(), Qt::ISODate);
        QString gender = json["gender"].toString();
        QString profilePictureFileName = json["profilePictureFileName"].toString();
        QString username = json["username"].toString();
        QString password = json["password"].toString();

        QVector<int> scores;
        QJsonArray arrayOfIntsArray = json["arrayOfInts"].toArray();
        for (int i = 0; i < arrayOfIntsArray.size(); ++i) {
            scores.append(arrayOfIntsArray[i].toInt());
        }
        User user(firstName, lastName, dateOfBirth, gender, profilePictureFileName, username, password, scores, false);
        users.append(user);
    }
}




// Password validation and checking

QString Init::passwordHash(QString &password)
{
    QByteArray passwordBytes = password.toUtf8();

    QCryptographicHash hasher(QCryptographicHash::Sha256);
    hasher.addData(passwordBytes);
    QByteArray hash = hasher.result();

    QString hashString = hash.toHex();

    return hashString;
}

void Init::validatePassword(QString &password, bool signupOrLogin)
{
    if (password.length() < 8)
        throw std::runtime_error("Password must be at least 8 characters long.");

    bool hasCapitalLetter = false;
    bool hasSpecialCharacter = false;
    bool hasSpace = false;

    for (QChar &ch : password) {
        if (ch.isUpper())
            hasCapitalLetter = true;

        if (ch.isSpace())
            hasSpace = true;

        if (!ch.isLetterOrNumber())
            hasSpecialCharacter = true;
    }

    // True: sign-up
    // False: Login
    if (signupOrLogin){
        // Write error message to to sign-up page
        if (!hasCapitalLetter)
            throw std::runtime_error("Password must have at least one capital letter.");

        if (!hasSpecialCharacter)
            throw std::runtime_error("Password must have at least one special character.");

        if (hasSpace)
            throw std::runtime_error("Password must not contain any spaces.");
    }
    else {
        // Write error message to login page
        if (!hasCapitalLetter)
            throw std::runtime_error("Password must have at least one capital letter.");

        if (!hasSpecialCharacter)
            throw std::runtime_error("Password must have at least one special character.");

        if (hasSpace)
            throw std::runtime_error("Password must not contain any spaces.");
    }

}

//check password at login
bool Init::checkPassword(QString &password, User &user, bool signupOrLogin)
{
    if ( user.password() != passwordHash(password) ) {
        if (signupOrLogin){
            //Write error msg to the sign-up page
        }
        else {
            //Write error msg to the login page
        }
        return false;
    }
    else return true;
}
