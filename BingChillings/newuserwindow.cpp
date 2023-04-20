#include "newuserwindow.h"
#include "ui_newuserwindow.h"

NewUserWindow::NewUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);
    ui->genderComboBox->addItem("Male");
    ui->genderComboBox->addItem("Female");
    ui->genderComboBox->addItem("Other");

    firstName = ui->firstNameEdit->text();
    lastName = ui->lastNameEdit->text();
    dateBirth = ui->birthdayEdit->date();
    gender = ui->genderComboBox->currentText();
    profilePicPath = "xxxx";
    username = ui->usernameEdit->text();
    password = ui->passwordEdit->text();


}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}

bool NewUserWindow::validateUsername() {
    bool isValidate = false;
    if (username.length() < 3) {
//        throw std::runtime_error("Username must be at least 3 characters long.");
        return isValidate;
    }

    bool hasInvalidCharacter = false;

    for (QChar &ch : username) {
        if (!ch.isLetterOrNumber() || ch.isSpace()) {
            hasInvalidCharacter = true;
            break;
        }
    }

    if (hasInvalidCharacter) {
//        throw std::runtime_error("Username must not contain special characters or spaces.");
        return isValidate;
    }

    return true;

}

bool NewUserWindow::validatePassword(){
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

    // True: sign-up
    // False: Login
    if (signupOrLogin){
        // Write error message to to sign-up page
        if (!hasCapitalLetter)
            throw std::runtime_error("Password must have at least one capital letter.");

        if (!hasSpecialCharacter)
            throw std::runtime_error("Password must have at least one special character.");

        if (hasSpace)
            throw std::runtime_error("Password must not contain any spaces.");
    }
    else {
        // Write error message to sign up page
        if (!hasCapitalLetter)
            throw std::runtime_error("Password must have at least one capital letter.");

        if (!hasSpecialCharacter)
            throw std::runtime_error("Password must have at least one special character.");

        if (hasSpace)
            throw std::runtime_error("Password must not contain any spaces.");
    }


}

void NewUserWindow::setNewUserInfo()
{
    if(validatePassword() == true && validateUsername() == true){
        User* newUser = new User(firstName, lastName, dateBirth, gender, profilePicPath, username, password, emptyVector, true);

    }



}
