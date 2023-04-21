#include "newuserwindow.h"
#include "ui_newuserwindow.h"
#include "loginform.h"
#include "init.h"


NewUserWindow::NewUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);

    this->users = Init::users;

    // Check which profile picture did the user pick
    connect(ui->dogIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->carIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->catIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->heartIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->icecreamIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->monsterIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->moonIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->planeIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->starIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->sunIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->treeIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);
    connect(ui->wheatIconButton, &QPushButton::clicked, this, &NewUserWindow::dogProfilePic);

    // Submit
    connect(ui->submitPushButton, &QPushButton::clicked, this, &NewUserWindow::backToLogin);
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}


void NewUserWindow::backToLogin()
{
    // Create a user:
    QString firstName = this->ui->firstNameEdit->text();
    QString lastName = this->ui->lastNameEdit->text();
    QDate birthday = this->ui->birthdayEdit->date();
    QString gender = this->ui->genderComboBox->currentText();
    QString profilePictureFileName = this->profilePicName;
    QString username = this->ui->usernameEdit->text();
    QString password = this->ui->passwordEdit->text();
    QVector<int> scores = {};
    bool hashNeeded = true;
    User newUser(firstName, lastName, birthday, gender, profilePictureFileName, username, password, scores, hashNeeded);

    this->user = newUser;

    // Write this newly created user to the JSON file
    user.write();

    LoginForm *loginWindow = new LoginForm();
    loginWindow->show();
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

