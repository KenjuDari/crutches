#include "mycolorcell.h"

MyColorCell::MyColorCell(QWidget *parent) : MyImage(parent)
{

}

MyColorCell::MyColorCell(QSize sizeFrom, MyColor colorFrom, int positionCol__, int positionRow__, QWidget *parent) : MyImage(parent)
{
    color_ = colorFrom;
    colorBase_ = colorFrom;
    positionCol_ = positionCol__;
    positionRow_ = positionRow__;
    sizeCell_ = sizeFrom;
    QPixmap pixmap = QPixmap(resource_pictures + "C" + QString::number(colorBase_) + ".png");
    setPixmapCell(pixmap);
}

void MyColorCell::SetColor(MyColor colorFrom)
{
    color_ = colorFrom;
    QPixmap pixmap = QPixmap(resource_pictures + "C" + QString::number(colorFrom) + ".png");
    setPixmapCell(pixmap);
}

void MyColorCell::setPixmapCell(QPixmap pixmapFrom)
{
    setBasePixmap(pixmapFrom.scaled(sizeCell_.width(), sizeCell_.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setNewPixmap(pixmapFrom.scaled(size().width(), size().height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

MyColor MyColorCell::getColor()
{
    return colorBase_;
}


void MyColorCell::runningCellLeft(int positionCol, int positionRow)
{
    if ((positionCol == positionCol_) && (positionRow == positionRow_))
    {
        SetColor(colorBase_);
    }
}

void MyColorCell::changeColor(MyColorCell *findCell, MyColor colorFrom)
{
    if (findCell == this) {
        SetColor(colorFrom);
    }
}
