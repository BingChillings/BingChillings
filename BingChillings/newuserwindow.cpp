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
    ui->genderComboBox->addItem("Male");
    ui->genderComboBox->addItem("Female");
    ui->genderComboBox->addItem("Other");
>>>>>>> Stashed changes

}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}

void setNewUserInfo()
{


}
