#include "user.h"
#include <QJsonDocument>
#include <QFile>
#include <QCryptographicHash>
#include "init.h"

// If first time creating that user put true for hashNeeded
User::User( QString &firstName, QString &lastName, QDate &dateOfBirth,
           QString &gender, QString &profilePictureFileName, QString &username,
           QString &password, QVector<int> &arrayOfInts , bool hashNeeded) :
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
            password_ = Init::passwordHash(password);
            // Also check username
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

    QFile file(":/JSON/JSON/users.json");
    if (file.open(QIODevice::WriteOnly)){
        QJsonDocument jsonDoc(jsonArray);
        file.write(jsonDoc.toJson());
    }
}






