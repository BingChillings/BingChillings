#include "user.h"
#include <QJsonDocument>
#include <QFile>
#include <QCryptographicHash>
#include <QCoreApplication>
#include <QDir>
#include <QFileDialog>
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

    // Write to the JSON file
    QJsonObject userObject;
    userObject["firstName"] = this->firstName();
    userObject["lastName"] = this->lastName();
    userObject["dateOfBirth"] = this->dateOfBirth().toString(Qt::ISODate);
    userObject["gender"] = this->gender();
    userObject["profilePictureFileName"] = this->profilePictureFileName();
    userObject["username"] = this->username();
    userObject["password"] = this->password();
//    userObject["scores"] = QJsonArray::fromVector(QVector<QVariant>::fromList(this->scores()));

    QFile jsonFile("/Users/yutianqin/bingChilling/BingChillings/BingChillings/users.json");
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

//    QJsonDocument jsonDocument(userObject);
//    jsonFile.write(jsonDocument.toJson());
//    jsonFile.close();


    // Read the existing JSON data from the file
    QJsonDocument doc = QJsonDocument::fromJson(jsonFile.readAll());

    // Get the root JSON object as a QJsonObject
    QJsonObject jsonObj = doc.object();


    // Add the new object to the existing JSON data as an array element
    QJsonArray jsonArray = jsonObj[this->username()].toArray();
    jsonArray.append(userObject);
    jsonObj[this->username()] = jsonArray;

    jsonFile.seek(0);
    jsonFile.write(QJsonDocument(jsonObj).toJson());
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




//void User::validateUsername(QString &username) {
//    if (username.length() < 3) {
//        throw std::runtime_error("Username must be at least 3 characters long.");
//    }

//    bool hasInvalidCharacter = false;

//    for (QChar &ch : username) {
//        if (!ch.isLetterOrNumber() || ch.isSpace()) {
//            hasInvalidCharacter = true;
//            break;
//        }
//    }

//    if (hasInvalidCharacter) {
//        throw std::runtime_error("Username must not contain special characters or spaces.");
//    }
//}

//check password at login
//bool User::checkPassword(QString &password, User &user){
//    if (user.password() != passwordHash(password) ){
//        return false;
//    }else {
//        return true;
//    }
//}






//void User::write()
//{
//    QJsonObject userObject;
//    userObject["firstName"] = this->firstName();
//    userObject["lastName"] = this->lastName();
//    userObject["dateOfBirth"] = this->dateOfBirth().toString(Qt::ISODate);
//    userObject["gender"] = this->gender();
//    userObject["profilePictureFileName"] = this->profilePictureFileName();
//    userObject["username"] = this->username();
//    userObject["password"] = this->password();
////    userObject["scores"] = QJsonArray::fromVector(QVector<QVariant>::fromList(this->scores()));

//    QFile jsonFile(":/JSON/temp.json");
//    if (!QFile::exists(jsonFile.fileName())) {
//        qDebug() << "JSON file does not exist";
//        return;
//    }

//    QFileDevice::Permissions newPermissions = QFileDevice::ReadOwner | QFileDevice::WriteOwner |
//                                              QFileDevice::ReadUser | QFileDevice::WriteUser |
//                                              QFileDevice::ReadOther;
//    if (!QFile::setPermissions(jsonFile.fileName(), newPermissions)) {
//        qDebug() << "Failed to set permissions";
//    }

//    if (!(QFile::permissions(jsonFile.fileName()))) {
//        qDebug() << "User does not have write permission for JSON file";
//        return;
//    }
//    if (!jsonFile.open(QIODevice::WriteOnly)) {
//        qDebug() << "Failed to open JSON file for writing";
//        return;
//    }
//    QJsonDocument jsonDocument(userObject);
//    jsonFile.write(jsonDocument.toJson());
//    jsonFile.close();
//}




//void User::write(){

//    QJsonArray jsonArray;

//    for (User &user : users) {
//        QJsonObject json;

//        json["firstName"] = user.firstName();
//        json["lastName"] = user.lastName();
//        json["dateOfBirth"] = user.dateOfBirth().toString(Qt::ISODate);
//        json["gender"] = user.gender();
//        json["profilePictureFileName"] = user.profilePictureFileName();
//        json["username"] = user.username();
//        json["password"] = user.password();

//        QJsonArray arrayOfIntsArray;
//        for (int value : user.scores()) {
//            arrayOfIntsArray.append(value);
//        }
//        json["arrayOfInts"] = arrayOfIntsArray;

//        jsonArray.append(json);
//    }

//    QFile file(":/JSON/JSON/users.json");
//    if (file.open(QIODevice::WriteOnly)){
//        QJsonDocument jsonDoc(jsonArray);
//        file.write(jsonDoc.toJson());
//    }
//}






