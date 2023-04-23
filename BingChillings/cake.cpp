#include "cake.h"

Cake::Cake()
{
    setPixmap((QPixmap(":/images/cake.png")).scaled(30,30));
    speed = 5; // Default speed
}

Cake::Cake(int speed)
{
    setPixmap((QPixmap(":/images/cake.png")).scaled(30,30));
    this->speed = speed;
}

void Cake::move_star()
{
    setPos(x(), y() + speed);

    // If the cake goes off the bottom of the scene, remove it
    if ((y() > scene()->height())) {
        scene()->removeItem(this);
        delete this;
    }
}
