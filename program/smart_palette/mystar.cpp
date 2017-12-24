#include "mystar.h"

MyStar::MyStar(QWidget *parent) : MyImage(parent)
{
    setBasePixmap(QPixmap(resource_pictures + "star0.png"));
    setNewPixmap(QPixmap(resource_pictures + "star0.png"));
}

void MyStar::setSerialNumber(int num)
{
    serialNumber_ = num;
}

bool MyStar::getActive()
{
    return active;
}

void MyStar::setActive(int numStar)
{
    if (numStar >= serialNumber_) {
        active = true;
    }
    else {
        active = false;
    }
    setNewPixmap(QPixmap(resource_pictures + "star" + QString::number(active) + ".png"));
}
