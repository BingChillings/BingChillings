#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playButtonPressed(){

}

void MainWindow::highScoreButtonPressed(){

}

void MainWindow::leaderBoardButtonPressed(){

}

void MainWindow::setUserForm(QString img, QString username){
    ui->userIcon->setIcon(QIcon(img));
    ui->userIcon->setIconSize(QSize(50,50));
    ui->usernameLabel->setText(username);
}

void MainWindow::setGuestForm(){
    ui->usernameLabel->setText("Guest");
    ui->userIcon->setIcon(QIcon(":/images/images/ice-cream.png"));
    ui->userIcon->setIconSize(QSize(50,50));
}
