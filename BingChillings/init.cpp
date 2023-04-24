#include <QFile>
#include <QJsonDocument>
#include <QCryptographicHash>
#include "init.h"


QVector<User> Init::users;


Init::Init()
{
    this->users = readFromJSON();
    qDebug() << "hello world";
    if (users.isEmpty()) {
        qDebug() << "The vector is empty";
    } else {
        qDebug() << "The vector is not empty";
    }

}



QVector<User> Init::readFromJSON()
{
    QVector<User> users;
    QFile file("/Users/yutianqin/bingChilling/BingChillings/BingChillings/users.json");

    if (file.open(QIODevice::ReadOnly)) {
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
        if (doc.isNull()) {
            qWarning("Failed to parse JSON: %s", error.errorString().toUtf8().constData());
        }
        qDebug() << "readFromJSON: Failed to open file for reading.";
        return users;
    }

    QByteArray fileContent = file.readAll();

    QJsonDocument jsonDocument(QJsonDocument::fromJson(fileContent));
    if (jsonDocument.isArray()){
        qDebug() << "readFromJSON: This json doc is not an array.";
        return users;
    }
    if (jsonDocument.isNull()){
        qDebug() << "readFromJSON: This file is null.";
        return users;
    }
    QJsonArray jsonArray = jsonDocument.array();


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
        User user(firstName, lastName, dateOfBirth, gender, profilePictureFileName, username, password, scores);
        this->users.append(user);
    }
    file.close();
    return users;
}









