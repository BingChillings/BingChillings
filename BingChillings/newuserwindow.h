#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H

#include <QMainWindow>

namespace Ui {
class NewUserWindow;
}

class NewUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewUserWindow(QWidget *parent = nullptr);
    ~NewUserWindow();

    void validateUsername(QString &username);
    void validatePassword(QString &password);

private:
    Ui::NewUserWindow *ui;
};

#endif // NEWUSERWINDOW_H
