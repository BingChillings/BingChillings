#include "gamescene.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 750;

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::playButtonPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playButtonPressed(){
    GameScene* game_scene = new GameScene();
    QGraphicsView* view = new QGraphicsView();
    view->setScene(game_scene);
    view->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    view->show();
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
