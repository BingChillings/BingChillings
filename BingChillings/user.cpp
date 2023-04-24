#include "user.h"
#include <QJsonDocument>
#include <QFile>
#include <QCryptographicHash>
#include <QCoreApplication>
#include <QDir>
#include <QFileDialog>
#include <QJsonObject>
#include "init.h"



User::User() :
    firstName_(""),
    lastName_(""),
    dateOfBirth_(QDate()),
    gender_(""),
    profilePictureFileName_(""),
    username_(""),
    password_(""),
    scores_(QVector<int>())
{
    // Default constructor implementation
}


User::User(QString &firstName, QString &lastName, QDate &dateOfBirth,
           QString &gender, QString &profilePictureFileName, QString &username,
           QString &password, QVector<int> &arrayOfInts) :
    firstName_(firstName),
    lastName_(lastName),
    dateOfBirth_(dateOfBirth),
    gender_(gender),
    profilePictureFileName_(profilePictureFileName),
    username_(username),
    password_(password),
    scores_(arrayOfInts)
{
}

QString User::firstName(){
    return firstName_;
}

QString User::lastName(){
    return lastName_;
}

QDate User::dateOfBirth(){
    return dateOfBirth_;
}

QString User::gender(){
    return gender_;
}

QString User::profilePictureFileName(){
    return profilePictureFileName_;
}

QString User::username() const {
    return username_;
}

QString User::password() const {
    return password_;
}

QVector<int> User::scores(){
    return scores_;
}



void User::write()
{
    // Write to the global QVector of the Init class
    Init::users.append(*this);

    // create a vector of userName objects
    QVector<QJsonObject> userNameObjects;

    for(int i = 0; i < Init::users.length(); i++){
        QJsonObject userInfoObject;
        QJsonObject userNameObject;

        userInfoObject["firstName"] = this->firstName();
        userInfoObject["lastName"] = this->lastName();
        userInfoObject["dateOfBirth"] = this->dateOfBirth().toString(Qt::ISODate);
        userInfoObject["gender"] = this->gender();
        userInfoObject["profilePictureFileName"] = this->profilePictureFileName();
        userInfoObject["password"] = this->password();

        userNameObject[this->username()] = userInfoObject;

        userNameObjects.append(userNameObject);
    }

    QJsonArray jsonArray;

    for (auto singleUserNameobject : userNameObjects) {
        jsonArray.append(singleUserNameobject);
    }

    // Write to the JSON file
//    QJsonObject userInfoObject;
//    QJsonObject userNameObject;

//    userInfoObject["firstName"] = this->firstName();
//    userInfoObject["lastName"] = this->lastName();
//    userInfoObject["dateOfBirth"] = this->dateOfBirth().toString(Qt::ISODate);
//    userInfoObject["gender"] = this->gender();
//    userInfoObject["profilePictureFileName"] = this->profilePictureFileName();
////    userInfoObject["username"] = this->username();
//    userInfoObject["password"] = this->password();
//    //    userObject["scores"] = QJsonArray::fromVector(QVector<QVariant>::fromList(this->scores()));
////    userNameObject.insert(this->username(), userInfoObject);
//     userNameObject[this->username()] = userInfoObject;
    //    QString dir_path;
    //    QDir dir(QCoreApplication::applicationDirPath());
    //    dir_path = dir.relativeFilePath("../../");
    //    QString filename = QFileDialog::getOpenFileName(this,"MSD",dir_path,tr())

    QFile jsonFile("/Users/xsyang/Documents/GitHub/BingChillings/BingChillings/JSON/users.json");
    if (!QFile::exists(jsonFile.fileName())) {
        qDebug() << "write: JSON file does not exist";
        return;
    }
    if (!(QFile::permissions(jsonFile.fileName()))) {
        qDebug() << "write: User does not have write permission for JSON file";
        return;
    }
    if (!jsonFile.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append)) {
        qDebug() << "write: Failed to open JSON file for writing" << jsonFile.errorString();
        return;
    }
    QJsonDocument doc(jsonArray);
    jsonFile.write(doc.toJson());
    jsonFile.close();
}



QString User::passwordHash(QString &password) {
    QByteArray passwordBytes = password.toUtf8();

    QCryptographicHash hasher(QCryptographicHash::Sha256);
    hasher.addData(passwordBytes);
    QByteArray hash = hasher.result();

    QString hashString = hash.toHex();

    return hashString;
}



bool User::checkPassword(QString &password, User &user){
    if (user.password() != passwordHash(password) ){
        return false;
    }else {
        return true;
    }
}





