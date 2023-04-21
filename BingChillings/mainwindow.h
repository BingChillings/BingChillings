#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
