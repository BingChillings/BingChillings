#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include "user.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

    QVector<User> users;
//    void setForNewUser(const QString &username);


private:
    Ui::LoginForm *ui;


private slots:
    void newUserForm();
    void validateUsernamePassword();
    void enterAsGuest();
};

#endif // LOGINFORM_H
