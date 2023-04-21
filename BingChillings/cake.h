#ifndef CAKE_H
#define CAKE_H

#include <QObject>
#include <QtWidgets>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Cake : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Cake(); // Defaults to speed of 5
    Cake(int speed);

public slots:
    void move_star();

private:
    int speed; // how far to move with each move call
};

#endif // CAKE_H
