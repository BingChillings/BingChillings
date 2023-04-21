#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H

#include <QWidget>

namespace Ui {
class NewUserWindow;
}

class NewUserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewUserWindow(QWidget *parent = nullptr);
    ~NewUserWindow();

private slots:
    void fillUserInfo();
    void resetFields();


private:
    Ui::NewUserWindow *ui;
    void setupGenderBox();
};

#endif // NEWUSERWINDOW_H
