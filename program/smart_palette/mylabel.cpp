#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

MyLabel::MyLabel(int sizeSriftBase, int widthBase, int heightBase, int posX, int posY, QWidget *parent) : QLabel(parent)
{
    sizeSriftBase_ = sizeSriftBase;
    posX_ = posX;
    posY_ = posY;
    widthBase_ = widthBase;
    heightBase_ = heightBase;
}

void MyLabel::setMyGeometry(int sizeSriftBase, int widthBase, int heightBase, int posX, int posY)
{
    sizeSriftBase_ = sizeSriftBase;
    posX_ = posX;
    posY_ = posY;
    widthBase_ = widthBase;
    heightBase_ = heightBase;
}

void MyLabel::getRatio(double percent)
{
    posXNow_ = posX_ * percent;
    posYNow_ = posY_ * percent;
    widthNow_ = widthBase_ * percent;
    heightNow_ =  heightBase_ * percent;
    setGeometry(posXNow_, posYNow_, widthNow_, heightNow_);
    QFont resizeFont = font();
    resizeFont.setPointSize(sizeSriftBase_ * percent);
    setFont(resizeFont);
}

void MyLabel::setPos(int posX, int posY)
{
    setGeometry(posXNow_ + posX, posYNow_ + posY, widthNow_, heightNow_);
}
