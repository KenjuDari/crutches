#ifndef MYSTAR_H
#define MYSTAR_H

#include <QWidget>
#include "myimage.h"

class MyStar : public MyImage
{
    Q_OBJECT
public:
    explicit MyStar(QWidget *parent = 0);
    void setSerialNumber(int num);  //номер по порядку
    bool getActive();  //активация подсвечивания

signals:

public slots:
    void setActive(int numStar);  // принимает набранный рекорд
                                  // если номер по порядку не меньше рекорда, то звезда загорается

private:
    int serialNumber_{0};
    bool active{0};
};

#endif // MYSTAR_H
