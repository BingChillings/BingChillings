//#include "loginform.h"
//#include "ui_loginform.h"
//#include "mainwindow.h"
//#include "newuserwindow.h"

//LoginForm::LoginForm(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::LoginForm)
//{
//    ui->setupUi(this);
//    connect(ui->submitPushButton, &QPushButton::clicked, this, &LoginForm::validateUsernamePassword);
//    connect(ui->newUserButton, &QPushButton::clicked, this, &LoginForm::newUserForm);
//    connect(ui->guestButton, &QPushButton::clicked, this, &LoginForm::enterAsGuest);
//}

//LoginForm::~LoginForm()
//{
//    delete ui;
//}

//void LoginForm::validateUsernamePassword()
//{
//    QString userName = ui->usernameLineEdit->text();
//    QString passWord = ui->passwordLineEdit->text();


//}

//void LoginForm::newUserForm()
//{
//    NewUserWindow *newUserWindow = new NewUserWindow();
//    newUserWindow->show();
//}

//void LoginForm::enterAsGuest()
//{
//    MainWindow *mainWindow = new MainWindow();
//    mainWindow->setGuestForm();
//    mainWindow->show();
//}
