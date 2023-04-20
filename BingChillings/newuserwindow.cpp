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
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}
