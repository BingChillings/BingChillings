#include "newuserwindow.h"
#include "ui_newuserwindow.h"

NewUserWindow::NewUserWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);
<<<<<<< Updated upstream
    ui->comboBoxGender->addItem("Male");
    ui->comboBoxGender->addItem("Female");

    ui->comboBoxPofilePic->addItem("image1");
    ui->comboBoxPofilePic->addItem("image2");
    ui->comboBoxPofilePic->addItem("image3");
    ui->comboBoxPofilePic->addItem("image4");
    ui->comboBoxPofilePic->addItem("image5");
=======
    connect(ui->submitButton, &QPushButton::clicked, this, &NewUserWindow::validateUsername);
>>>>>>> Stashed changes
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}




void NewUserWindow::validateUsername(QString &username) {
    if (username.length() < 3) {
        ui->errorLineEdit->setText("Username must be at least 3 characters long.");
        return;
//        throw std::runtime_error("Username must be at least 3 characters long.");
    }

    bool hasInvalidCharacter = false;

    for (QChar &ch : username) {
        if (!ch.isLetterOrNumber() || ch.isSpace()) {
            hasInvalidCharacter = true;
            break;
        }
    }

    if (hasInvalidCharacter) {
        ui->errorLineEdit->setText("Username must not contain special characters or spaces.");
//        throw std::runtime_error("Username must not contain special characters or spaces.");
    }
}



void NewUserWindow::validatePassword(QString &password)
{
    if (password.length() < 8)
        throw std::runtime_error("Password must be at least 8 characters long.");

    bool hasCapitalLetter = false;
    bool hasSpecialCharacter = false;
    bool hasSpace = false;

    for (QChar &ch : password) {
        if (ch.isUpper())
            hasCapitalLetter = true;

        if (ch.isSpace())
            hasSpace = true;

        if (!ch.isLetterOrNumber())
            hasSpecialCharacter = true;
    }

    // Write error message to login page
    if (!hasCapitalLetter)
        throw std::runtime_error("Password must have at least one capital letter.");

    if (!hasSpecialCharacter)
        throw std::runtime_error("Password must have at least one special character.");

    if (hasSpace)
        throw std::runtime_error("Password must not contain any spaces.");
}
