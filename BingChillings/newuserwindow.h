#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H

#include <QWidget>
#include "user.h"

namespace Ui {
class NewUserWindow;
}

class NewUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewUserWindow(QWidget *parent = nullptr);
    ~NewUserWindow();

    QVector<User> users;

    User user;
    QString profilePicName;

    void backToLogin();

    void dogProfilePic();
    void carProfilePic();
    void catProfilePic();
    void heartProfilePic();
    void icecreamProfilePic();
    void monsterProfilePic();
    void moonProfilePic();
    void planeProfilePic();
    void starProfilePic();
    void sunProfilePic();
    void treeProfilePic();
    void wheatProfilePic();

private:
    Ui::NewUserWindow *ui;
};

#endif // NEWUSERWINDOW_H
