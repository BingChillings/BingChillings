
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    game_scene = new GameScene();
    view = new QGraphicsView();
    view->setScene(game_scene);
    view->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    view->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    view->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    connect(game_scene, &GameScene::end_game, this, &MainWindow::handleGameEnd);
    view->show();
}

//slot for end game
void MainWindow::handleGameEnd(QString type, int lives, int score)
{
    view->close();
    //update text box once it's available.
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
