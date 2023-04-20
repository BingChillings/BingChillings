#include "newuserwindow.h"
#include "ui_newuserwindow.h"

NewUserWindow::NewUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);
    ui->comboBoxGender->addItem("Male");
    ui->comboBoxGender->addItem("Female");
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}
