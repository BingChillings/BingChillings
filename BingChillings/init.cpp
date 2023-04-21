#include <QFile>
#include <QJsonDocument>
#include <QCryptographicHash>
#include "init.h"



Init::Init(){}



void Init::readFromJSON()
{
    QFile file(":/JSON/JSON/users.json");
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



//check password at login
bool Init::checkPassword(QString &password, User &user)
{
    if ( user.password() != passwordHash(password) ) return false;
    else return true;
}






