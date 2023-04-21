#include "QtCore/qdatetime.h"
#include "gamescene.h"
#include "highscoresform.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include "init.h"

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 750;

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->users = Init::users;

    setDate();
    connect(ui->playButton, &QPushButton::clicked, this, &MainWindow::playButtonPressed);
    connect(ui->highScoresButton, &QPushButton::clicked, this, &MainWindow::highScoreButtonPressed);
    connect(ui->leaderBoardButton, &QPushButton::clicked, this, &MainWindow::leaderBoardButtonPressed);
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
    HighScoresForm *highScoreForm = new HighScoresForm();
    //highScoreForm->setScoreBoard(scores, true); // Need to add QVector<int> scores
    highScoreForm->show();
}

void MainWindow::leaderBoardButtonPressed(){
    HighScoresForm *highScoreForm = new HighScoresForm();
    //highScoreForm->setScoreBoard(scores, false); // Need to add QVector<int> scores
    highScoreForm->show();
}

void MainWindow::setUserForm(QString img, QString username){
    ui->usernameLabel->setText(username);
    ui->userIcon->setIcon(QIcon(img));
    ui->userIcon->setIconSize(QSize(50,50));

}

void MainWindow::setGuestForm(){
    ui->usernameLabel->setText("Guest");
    ui->userIcon->setIcon(QIcon(":/images/images/ice-cream.png"));
    ui->userIcon->setIconSize(QSize(50,50));
}

void MainWindow::setDate(){
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("ddd MMMM d yyyy");
    ui->dateLineEdit->setText(formattedTime);
}


