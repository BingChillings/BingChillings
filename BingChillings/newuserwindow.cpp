#include "newuserwindow.h"
#include "ui_newuserwindow.h"

NewUserWindow::NewUserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}
