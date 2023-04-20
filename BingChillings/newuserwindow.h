#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H

#include <QMainWindow>

#include "user.h"


namespace Ui {
class NewUserWindow;
}

class NewUserWindow : public QMainWindow
{
    Q_OBJECT
    User* newUser;

public:
    explicit NewUserWindow(QWidget *parent = nullptr);
    ~NewUserWindow();
    void setNewUserInfo();

private:
    Ui::NewUserWindow *ui;
};

#endif // NEWUSERWINDOW_H
