#include <QFile>
#include <QJsonDocument>
#include <QCryptographicHash>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
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
    QDir currnetDir = QDir::current();
    QString filePath = currnetDir.relativeFilePath("../../../../BingChillings/users.json");
    QJsonArray jsonArray;
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)) {
        QByteArray fileContent = file.readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(fileContent);

        if (jsonDocument.isNull()){
            return users;
        }

        jsonArray = jsonDocument.array();
    }
    else {
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
    jsonArray = jsonDocument.array();


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
        QJsonArray arrayOfIntsArray = json["scores"].toArray();

        for (int i = 0; i < arrayOfIntsArray.size(); ++i) {
            scores.append(arrayOfIntsArray[i].toInt());
        }
        User user(firstName, lastName, dateOfBirth, gender, profilePictureFileName, username, password, scores);
        this->users.append(user);
    }
    file.close();

    for(User &u : users){
        qDebug() << u.username();
    }
    return users;
}









