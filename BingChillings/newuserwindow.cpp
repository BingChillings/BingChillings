#include "newuserwindow.h"
#include "ui_newuserwindow.h"
#include "init.h"
#include <QPushButton>
#include <QCryptographicHash>


NewUserWindow::NewUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);

    setupGenderBox();
    connect(ui->submitButton, &QPushButton::clicked, this, &NewUserWindow::validateFields);
    connect(ui->resetButton, &QPushButton::clicked, this, &NewUserWindow::resetFields);

    // Check which profile picture did the user pick
    //    connect(ui->dogIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->carIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->catIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->heartIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->icecreamIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->monsterIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->moonIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->planeIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->starIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->sunIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->treeIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->wheatIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    //    connect(ui->submitPushButton, &QPushButton::clicked, this, &NewUserWindow::backToLogin);
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}



void NewUserWindow::setupGenderBox(){
    ui->genderComboBox->addItem("Male");
    ui->genderComboBox->addItem("Female");
    ui->genderComboBox->addItem("Other");
    ui->genderComboBox->addItem("Prefer Not to Say");
}



void NewUserWindow::resetFields(){
    QList<QPushButton *> listIcons = ui->userIconGroup->findChildren<QPushButton *>();
    for (auto icon : listIcons){
        icon->setAutoExclusive(false);
        icon->setChecked(false);
        icon->setAutoExclusive(true);
    }
    ui->icecreamIconButton->setChecked(true);
    ui->firstNameEdit->clear();
    ui->lastNameEdit->clear();
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();
    ui->genderComboBox->setCurrentIndex(-1);
    ui->birthdayEdit->setDate(QDate(2000,01,01));
}

void NewUserWindow::validateFields(){
    bool hasCapitalLetter = false;
    bool hasSpecialCharacter = false;
    bool hasSpace = false;

    QString firstname = ui->firstNameEdit->text();
    QString lastname = ui->lastNameEdit->text();
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    QString gender = ui->genderComboBox->currentText();
    QString profilePictureFileName;
    QDate birthday;

    for (QChar &ch : password) {
        if (ch.isUpper())
            hasCapitalLetter = true;

        if (ch.isSpace())
            hasSpace = true;

        if (!ch.isLetterOrNumber())
            hasSpecialCharacter = true;
    }

    // Write error message to to sign-up page
    if (firstname.length() == 0)
        ui->errorLineEdit->setText("Please enter a first name");

    else if (lastname.length() == 0)
        ui->errorLineEdit->setText("Please enter a last name");

    else if(username.length() == 0)
        ui->errorLineEdit->setText("Please enter a username");

    else if(username.length() < 3)
        ui->errorLineEdit->setText("Username must contain more than 3 characters");

    else if(password.length() < 8)
        ui->errorLineEdit->setText("Password must be at least 8 characters long.");

    else if (!hasCapitalLetter)
        ui->errorLineEdit->setText("Password must have at least one capital letter.");

    else if (!hasSpecialCharacter)
        ui->errorLineEdit->setText("Password must have at least one special character.");

    else if (hasSpace)
        ui->errorLineEdit->setText("Password must not contain any spaces.");

    else if (gender.isNull())
        ui->errorLineEdit->setText("Please select a gender");

    else
        ui->errorLineEdit->clear();


    if (ui->icecreamIconButton->isChecked()){
        profilePictureFileName = ":/images/images/ice-cream.png";
    }
    else if (ui->carIconButton->isChecked()){
        profilePictureFileName = ":/images/images/car.png";
    }
    else if (ui->dogIconButton->isChecked()){
        profilePictureFileName = ":/images/images/dog.png";
    }
    else if (ui->moonIconButton->isChecked()){
        profilePictureFileName = ":/images/images/moon.png";
    }
    else if (ui->planeIconButton->isChecked()){
        profilePictureFileName = ":/images/images/plane.png";
    }
    else if (ui->sunIconButton->isChecked()){
        profilePictureFileName = ":/images/images/sun.png";
    }
    else if (ui->treeIconButton->isChecked()){
        profilePictureFileName = ":/images/images/tree.png";
    }
    else if (ui->catIconButton->isChecked()){
        profilePictureFileName = ":/images/images/cat.png";
    }
    else if (ui->monsterIconButton->isChecked()){
        profilePictureFileName = ":/images/images/monster.png";
    }
    else if (ui->heartIconButton->isChecked()){
        profilePictureFileName = ":/images/images/heart.png";
    }
    else if (ui->starIconButton->isChecked()){
        profilePictureFileName = ":/images/images/star.png";
    }
    else if (ui->wheatIconButton->isChecked()){
        profilePictureFileName = ":/images/images/wheat.png";
    }

    birthday = ui->birthdayEdit->date();
    QVector<int> scores = {};

    QString hashedPassword = passwordHash(password);
    if ( hasCapitalLetter && hasSpecialCharacter && !hasSpace ) {
        User newUser(firstname, lastname, birthday, gender, profilePictureFileName, username, hashedPassword, scores);
        this->user = newUser;

        // Write this newly created user to the JSON file
        user.write();
        this->close();
        Init::users.append(user);
    }
}


QString NewUserWindow::passwordHash(QString &password)
{
    QByteArray passwordBytes = password.toUtf8();

    QCryptographicHash hasher(QCryptographicHash::Sha256);
    hasher.addData(passwordBytes);
    QByteArray hash = hasher.result();

    QString hashString = hash.toHex();

    return hashString;
}




void NewUserWindow::dogProfilePic()
{
    QPushButton *button = this->ui->dogIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::carProfilePic()
{
    QPushButton *button = this->ui->carIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::catProfilePic()
{
    QPushButton *button = this->ui->catIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::heartProfilePic()
{
    QPushButton *button = this->ui->heartIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::icecreamProfilePic()
{
    QPushButton *button = this->ui->icecreamIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::monsterProfilePic()
{
    QPushButton *button = this->ui->monsterIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::moonProfilePic()
{
    QPushButton *button = this->ui->moonIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::planeProfilePic()
{
    QPushButton *button = this->ui->planeIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::starProfilePic()
{
    QPushButton *button = this->ui->starIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::sunProfilePic()
{
    QPushButton *button = this->ui->sunIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}
void NewUserWindow::treeProfilePic()
{
    QPushButton *button = this->ui->wheatIconButton;
    QIcon icon = button->icon();
    profilePicName = icon.name();
}

bool NewUserWindow::isUserNameTaken(QString &usernameRequst)
{
    for ( User &u : Init::users) {
        if (u.username() == usernameRequst) {
            return true;
        }
    }
    return false;
}

