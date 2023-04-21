#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "user.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QVector<User> users;
    void setUserForm(QString img, QString username);
    void setGuestForm();

private:
    Ui::MainWindow *ui;
    void setDate();

private slots:
    void playButtonPressed();
    void highScoreButtonPressed();
    void leaderBoardButtonPressed();
};

#endif // MAINWINDOW_H
