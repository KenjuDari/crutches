#include "myrunningcell.h"
#include "mycolorcell.h"
#include <QKeyEvent>

MyRunningCell::MyRunningCell(QWidget *parent) : MyColorCell(parent)
{
    SetColor(MyColor::transparent);
}


MyRunningCell::MyRunningCell(QSize sizeFrom, int nCol, int nRow, MyColor winColor, MyColor colorFrom, int positionCol__, int positionRow__, QWidget *parent) :
    MyColorCell(sizeFrom, colorFrom, positionCol__, positionRow__, parent)
{
    SetColor(MyColor::transparent);
    nCol_ = nCol;
    nRow_ = nRow;
    winColor_ = winColor;
}


void MyRunningCell::takeStart()
{
    int rec(1);
    if ((sec_< 10) && (sumStep < 10))
    {
        rec++;
        if ((sec_< 4) && (sumStep < 8))
        {
            rec++;
        }
    }
    emit currentRecords(rec);
    BlendColor(familyCells_[1]);
    min_ = 0;
    sec_ = 0;
    sumStep = 0;
    currentColor = MyColor::white;
    emit yourColorChange(familyCells_[1], currentColor);
    emit iLeftYou(currentPosCol, currentPosRow);
    currentPosCol = 1;
    currentPosRow = 0;
    emit sendTime("<font color=red face=Franklin Gothic>00:00</font>");
    emit sendStep("<font color=black face=Franklin Gothic>" + QString::number(sumStep) + "</font>");
    emit moveStep(0, 0);
    show();

}


void MyRunningCell::setFamilyCells(MyColorCell ** family)
{
    familyCells_ = family;
}


void MyRunningCell::tick()
{
    QString min;
    QString sec;
    if ((running == true)&&(banPress == false)) {
        sec_++;
        if (sec_ == 60) {
            min_++;
            sec_ = 0;
        }
        if (sec_ < 10) {
            sec = QString::number(0) + QString::number(sec_);
        }
        else {
            sec = QString::number(sec_);
        }
        if (min_ < 10) {
            min = QString::number(0) + QString::number(min_);
        }
        else {
            min = QString::number(min_);
        }

        QString countdown = min + ":" + sec;
        emit sendTime("<font color=red face=Franklin Gothic>" + countdown + "</font>");
    }
    if ((sec_ >= 30)||(sumStep >= 20)) {
        running= false;
        banPress = true;
        winEnd(0);
    }
}


void MyRunningCell::restart()  // слот
{
    banPress = false;
    running = false;
    takeStart();
    emit finish(3);
    show();
    raise();
}

void MyRunningCell::BlendColor(MyColorCell* receiver)
{
    setParent(receiver);
    raise();
        MyColor colorFrom( receiver->getColor() );
        if (colorFrom * currentColor == 105) {
            currentColor = MyColor::white;
            emit yourColorChange(receiver, currentColor);
            return;
        }

        if (currentColor % colorFrom == 0) {
            currentColor = (MyColor) (currentColor / colorFrom);
            emit yourColorChange(receiver, currentColor);
            return;
        }

        if (colorFrom % currentColor == 0) {
            currentColor = (MyColor) ( colorFrom / currentColor);
            emit yourColorChange(receiver, currentColor);
            return;
        }

        if ((colorFrom % MyColor::green == 0) && (currentColor % MyColor::green == 0) ) {
            currentColor = (MyColor) (( currentColor / MyColor::green) * ( colorFrom / MyColor::green) );
            emit yourColorChange(receiver, currentColor);
            return;
        }

        if ((colorFrom % MyColor::red == 0) && (currentColor % MyColor::red == 0) ) {
            currentColor = (MyColor) (( currentColor / MyColor::red) * ( colorFrom / MyColor::red) );
           emit yourColorChange(receiver, currentColor);
           return;
        }

        if ((colorFrom % MyColor::blue == 0) && (currentColor % MyColor::blue == 0) ) {
          currentColor = (MyColor) (( currentColor / MyColor::blue) * (colorFrom / MyColor::blue) );
          emit yourColorChange(receiver, currentColor);
          return;
        }
        currentColor = (MyColor) ( currentColor * colorFrom );
        emit yourColorChange(receiver, currentColor);
}

void MyRunningCell::setPosition(QKeyEvent *event)
{
    if (running == false) {
        running = true;
        sec_ = 0;
        min_ = 0;
        emit startGame();
    }
    if (banPress == false)
    {
    switch (event->key()) {

    case Qt::Key_Left:
        if (currentPosCol > 0 ) {
            emit iLeftYou(currentPosCol, currentPosRow);
            takeStand(--currentPosCol, currentPosRow);
            emit sendStep("<font color=black face=Franklin Gothic>" + QString::number(++sumStep) + "</font>");
        }
        break;

    case Qt::Key_Right:
        if (currentPosCol < nCol_-1) {
            emit iLeftYou(currentPosCol, currentPosRow);
            takeStand(++currentPosCol, currentPosRow);
            emit sendStep("<font color=black face=Franklin Gothic>" + QString::number(++sumStep) + "</font>");
        }
        break;

    case Qt::Key_Down:
        if (currentPosRow < nRow_ - 1) {
            emit iLeftYou(currentPosCol, currentPosRow);
            takeStand(currentPosCol, ++currentPosRow);
            emit sendStep("<font color=black face=Franklin Gothic>" + QString::number(++sumStep) + "</font>");
        }
        else {
            if (currentColor == winColor_) {
               running= false;
               banPress = true;
               winEnd(1);
            }
        }
        break;

    case Qt::Key_Up:
        if (currentPosRow > 0) {
            emit iLeftYou(currentPosCol, currentPosRow);
            takeStand(currentPosCol, --currentPosRow);
            emit sendStep("<font color=black face=Franklin Gothic>" + QString::number(++sumStep) + "</font>");
        }
        break;
    default:
        break;
    }
    if (sumStep > 9)
    {
        emit moveStep(-17, 0);
    }
    else
    {
        emit moveStep(0, 0);
    }
        show();
    }
}


void MyRunningCell::takeStand(int iCol, int iRow)
{
    BlendColor(familyCells_[iRow * nCol_ + iCol]);
}

void MyRunningCell::winEnd(int state)
{
    takeStart();
    running = false;
    banPress = true;
    emit finish(state);
}
