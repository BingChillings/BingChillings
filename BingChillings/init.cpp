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
//    QJsonArray jsonArray;


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

            QJsonObject userInfoObject =  userNameObject[key].toObject();

            QString username = key;
            qDebug() << key << error.errorString();

            QString firstName = userInfoObject["firstName"].toString();
//            qDebug() << firstName << error.errorString();

            QString lastName = userInfoObject["lastName"].toString();
            QDate dateOfBirth = QDate::fromString(userInfoObject["dateOfBirth"].toString(), Qt::ISODate);
            QString gender = userInfoObject["gender"].toString();
            QString profilePictureFileName = userInfoObject["profilePictureFileName"].toString();
//            QString username = userInfoOject["username"].toString();
            QString password = userInfoObject["password"].toString();
            qDebug() << password << error.errorString();


            QVector<int> scores;

            User user(firstName, lastName, dateOfBirth, gender, profilePictureFileName, username, password, scores);
            users.push_back(user);

        }

    }



    file.close();
    return users;
}









