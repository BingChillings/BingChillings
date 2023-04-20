#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamescene.h"
#include <QGraphicsView>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT
    GameScene* game_scene;
    QGraphicsView* view;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUserForm(QString img, QString username);
    void setGuestForm();

private:
    Ui::MainWindow *ui;

private slots:
    void playButtonPressed();
    void handleGameEnd(QString type, int lives, int score);
    void highScoreButtonPressed();
    void leaderBoardButtonPressed();
};

#endif // MAINWINDOW_H
