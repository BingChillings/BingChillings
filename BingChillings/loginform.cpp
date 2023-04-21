#include "loginform.h"
#include "ui_loginform.h"

#include "mainwindow.h"
#include "newuserwindow.h"
#include "init.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>



LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    this->users = Init::users;

    connect(ui->submitPushButton, &QPushButton::clicked, this, &LoginForm::validateUsernamePassword);
    connect(ui->newUserButton, &QPushButton::clicked, this, &LoginForm::newUserForm);
    connect(ui->guestButton, &QPushButton::clicked, this, &LoginForm::enterAsGuest);
}

LoginForm::~LoginForm()
{
    delete ui;
}





void LoginForm::validateUsernamePassword()
{
    QString userName = ui->usernameLineEdit->text();
    QString passWord = ui->passwordLineEdit->text();

    User user;
    for ( User &u : users ) {
        if ( u.username() == userName ){
            user = u;
            if ( !u.checkPassword(passWord, u) ) {
                ui->errorMessageLabel->setText("Wrong password");
                return;
            }
        } else {
            ui->errorMessageLabel->setText("Cannot find the user");
            return;
        }
    }

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setUserForm(user.profilePictureFileName(), user.username());
    mainWindow->show();
}




void LoginForm::newUserForm()
{
    NewUserWindow *newUserWindow = new NewUserWindow();
    newUserWindow->show();
}

void LoginForm::enterAsGuest()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->setGuestForm();
    mainWindow->show();
    this->close();
}
