#ifndef MYCOLORCELL_H
#define MYCOLORCELL_H

#include <QWidget>
#include "myimage.h"

enum MyColor { transparent = 101, white = 1, green = 3, red = 5, blue = 7, yellow = 15, skiey = 21, purple = 35};

class MyColorCell : public MyImage
{
    Q_OBJECT
public:
    explicit MyColorCell(QWidget *parent = 0);
    explicit MyColorCell(QSize sizeFrom, MyColor colorFrom, int positionCol__, int positionRow__, QWidget *parent = 0);
    void SetColor(MyColor colorFrom);        // изменяет цвет кнопки на форме
    void setPixmapCell(QPixmap pixmapFrom);  // вызывается в SetColor и вызывает методы из MyImage
    MyColor getColor();

signals:

protected slots:
    void runningCellLeft (int positionCol, int positionRow);    // сигнал от ведущего кружка, что он покинул цветной кружок
                                                                // то есть возвращение к базовому цвету
    void changeColor(MyColorCell* findCell, MyColor colorFrom); // ведущий кружок наступил на цветной кружок, то есть необходимо изменить цвет

protected:
    MyColor color_{ (MyColor) 0 };
    MyColor colorBase_{ (MyColor) 0 };
    QSize sizeCell_{QSize(0,0) };
    int positionCol_{ 0 };
    int positionRow_{ 0 };
};

#endif // MYCOLORCELL_H
