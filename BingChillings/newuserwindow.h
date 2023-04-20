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

private:
    Ui::NewUserWindow *ui;
};

#endif // NEWUSERWINDOW_H
