#include "user.h"
#include <QJsonDocument>
#include <QFile>
#include <QCryptographicHash>

// If first time creating that user put true for hashNeeded
User::User( QString &firstName, QString &lastName, QDate &dateOfBirth, QString &gender, QString &profilePictureFileName, QString &username, QString &password, QVector<int> &arrayOfInts , bool hashNeeded) :
    firstName_(firstName),
    lastName_(lastName),
    dateOfBirth_(dateOfBirth),
    gender_(gender),
    profilePictureFileName_(profilePictureFileName),
    scores_(arrayOfInts)
{
    // If first time making user, then validate the password then hash
    if(hashNeeded){
        try {
            validatePassword(password);
            password_ = passwordHash(password);
            // Also check username
            validateUsername(username);
            username_ = username;
        } catch (const std::runtime_error &e) {
            qDebug() << "Error:" << e.what();
        }
    }
    // If reading from file then password is has already been validated and hashed
    else{
        password_ = password;
        username_ = username;
    }
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

QString User::username(){
    return username_;
}

QString User::password(){
    return password_;
}

QVector<int> User::scores(){
    return scores_;
}

QVector<User> User::read(){
    QVector<User> users;

    QFile file("users.json");
    QJsonArray jsonArray;

    if (file.open(QIODevice::ReadOnly)){
        QByteArray fileContent = file.readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(fileContent);

        if (jsonDocument.isNull()){
            qDebug() << "Failed to parse JSON from file.";
        }

        jsonArray = jsonDocument.array();
    }
    else{
        qDebug() << "Failed to open file for reading.";
    }

    for (int i = 0; i < jsonArray.size(); ++i) {
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

    return users;
}

void User::write(QVector<User> &users){

    QJsonArray jsonArray;

    for (User &user : users) {
        QJsonObject json;

        json["firstName"] = user.firstName();
        json["lastName"] = user.lastName();
        json["dateOfBirth"] = user.dateOfBirth().toString(Qt::ISODate);
        json["gender"] = user.gender();
        json["profilePictureFileName"] = user.profilePictureFileName();
        json["username"] = user.username();
        json["password"] = user.password();

        QJsonArray arrayOfIntsArray;
        for (int value : user.scores()) {
            arrayOfIntsArray.append(value);
        }
        json["arrayOfInts"] = arrayOfIntsArray;

        jsonArray.append(json);
    }

    QFile file("users.json");
    if (file.open(QIODevice::WriteOnly)){
        QJsonDocument jsonDoc(jsonArray);
        file.write(jsonDoc.toJson());
    }
}

QString User::passwordHash(QString &password) {
    QByteArray passwordBytes = password.toUtf8();

    QCryptographicHash hasher(QCryptographicHash::Sha256);
    hasher.addData(passwordBytes);
    QByteArray hash = hasher.result();

    QString hashString = hash.toHex();

    return hashString;
}

void User::validatePassword(QString &password){
    if (password.length() < 8) {
        throw std::runtime_error("Password must be at least 8 characters long.");
    }

    bool hasCapitalLetter = false;
    bool hasSpecialCharacter = false;
    bool hasSpace = false;

    for (QChar &ch : password) {
        if (ch.isUpper()) {
            hasCapitalLetter = true;
        }
        if (ch.isSpace()) {
            hasSpace = true;
        }
        if (!ch.isLetterOrNumber()) {
            hasSpecialCharacter = true;
        }
    }

    if (!hasCapitalLetter) {
        throw std::runtime_error("Password must have at least one capital letter.");
    }

    if (!hasSpecialCharacter) {
        throw std::runtime_error("Password must have at least one special character.");
    }

    if (hasSpace) {
        throw std::runtime_error("Password must not contain any spaces.");
    }

}

void User::validateUsername(QString &username) {
    if (username.length() < 3) {
        throw std::runtime_error("Username must be at least 3 characters long.");
    }

    bool hasInvalidCharacter = false;

    for (QChar &ch : username) {
        if (!ch.isLetterOrNumber() || ch.isSpace()) {
            hasInvalidCharacter = true;
            break;
        }
    }

    if (hasInvalidCharacter) {
        throw std::runtime_error("Username must not contain special characters or spaces.");
    }
}

//check password at login
bool User::checkPassword(QString &password, User &user){
    if (user.password() != passwordHash(password) ){
        return false;
    }else {
        return true;
    }
}

