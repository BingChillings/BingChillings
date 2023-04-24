#include <QFile>
#include <QJsonDocument>
#include <QCryptographicHash>
#include "init.h"



QVector<User> Init::users;


Init::Init()
{
    this->users = readFromJSON();
}


QVector<User> Init::readFromJSON()
{
    QVector<User> users;
    QFile file("/Users/xsyang/Documents/GitHub/BingChillings/BingChillings/JSON/users.json");
    QJsonArray jsonArray;


//    if (file.open(QIODevice::ReadOnly)) {
//        QByteArray fileContent = file.readAll();
//        QJsonDocument jsonDocument = QJsonDocument::fromJson(fileContent);

////        if (jsonDocument.isNull()){
////            qDebug() << "readFromJSON: This file is null.";
////        }

////        jsonArray = jsonDocument.array();
//    }
//    else {
//        qDebug() << "readFromJSON: Failed to open file for reading.";
//    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading";
    }

    QByteArray fileData = file.readAll();
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData, &error);


    if (jsonDocument.isNull() || !jsonDocument.isObject()) {
        qDebug() << "Failed to parse JSON document:" << error.errorString();
    }

    QJsonObject userNameObject = jsonDocument.object();


    for (const QString &key : userNameObject.keys()) {
        if(userNameObject[key].isObject()){

            QJsonObject userInfoOject =  userNameObject[key].toObject();

            QString username = key;
            qDebug() << key << error.errorString();

            QString firstName = userInfoOject["firstName"].toString();
            QString lastName = userInfoOject["lastName"].toString();
            QDate dateOfBirth = QDate::fromString(userInfoOject["dateOfBirth"].toString(), Qt::ISODate);
            QString gender = userInfoOject["gender"].toString();
            QString profilePictureFileName = userInfoOject["profilePictureFileName"].toString();
//            QString username = userInfoOject["username"].toString();
            QString password = userInfoOject["password"].toString();
            QVector<int> scores;
//            QJsonArray arrayOfIntsArray = userInfoOject["arrayOfInts"].toArray();
            User user(firstName, lastName, dateOfBirth, gender, profilePictureFileName, username, password, scores);
            this->users.append(user);
//            QVector<int> scores;
//            QJsonArray arrayOfIntsArray = json["arrayOfInts"].toArray();
        }
//        QJsonObject userNameObject = userNameObject.value(key).toObject();
//        jsonArray.append(userNameObject);
    }

//    for (int i = 0; i < jsonArray.size(); ++i)
//    {
//        QJsonObject userInfo = jsonArray[i].toObject();
//        QString firstName = json["firstName"].toString();
//        QString lastName = json["lastName"].toString();
//        QDate dateOfBirth = QDate::fromString(json["dateOfBirth"].toString(), Qt::ISODate);
//        QString gender = json["gender"].toString();
//        QString profilePictureFileName = json["profilePictureFileName"].toString();
//        QString username = json["username"].toString();
//        QString password = json["password"].toString();

//        QVector<int> scores;
//        QJsonArray arrayOfIntsArray = json["arrayOfInts"].toArray();
//        for (int i = 0; i < arrayOfIntsArray.size(); ++i) {
//            scores.append(arrayOfIntsArray[i].toInt());
//        }

    file.close();
    return users;
}









