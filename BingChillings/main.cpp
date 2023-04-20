#include "mainwindow.h"
#include "newuserwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    NewUserWindow w2;
    w2.show();
    return a.exec();
}
