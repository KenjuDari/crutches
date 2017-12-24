#include "mygridlayout.h"

MyGridLayout::MyGridLayout(QWidget *parent) : QGridLayout(parent)
{
}

void MyGridLayout::setBaseContentsMargins(int marginLeft, int marginTop, int marginRight, int marginBottom, int spacingNew)
{
    baseLeft_ = marginLeft;
    baseTop_ = marginTop;
    baseRight_ = marginRight;
    baseBottom_ = marginBottom;
    baseSpacing_ = spacingNew;
    setContentsMargins(baseLeft_, baseTop_,baseRight_, baseBottom_);
    setSpacing(baseSpacing_);
}

void MyGridLayout::getRatio(double percent)
{
    setContentsMargins(baseLeft_ * percent, baseTop_ * percent, baseRight_ * percent, baseBottom_ * percent);
    setSpacing(baseSpacing_ * percent);
}
