#ifndef MYRUNNINGCELL_H
#define MYRUNNINGCELL_H


#include <QWidget>
#include "mycolorcell.h"

class MyRunningCell : public MyColorCell
{
    Q_OBJECT
public:
    explicit MyRunningCell(QWidget *parent = 0);
    explicit MyRunningCell(QSize sizeFrom, int nCol, int nRow, MyColor winColor, MyColor colorFrom = MyColor::transparent, int positionCol__ = 1, int positionRow__ = 0, QWidget *parent = 0);
    void takeStart();                            // начальное положение
    void setFamilyCells(MyColorCell** family);   // принимает указатель на массив кружков, по которым в дальнейшем будет бегать

signals:
    void finish(int);  // выиграл или проиграл
    void iLeftYou(int, int);  // отправляет сигнал кнопке, с которой сошел, то есть возвращает ей базовый цвет
    void yourColorChange (MyColorCell*, MyColor); // задает цвет кружку, на который встал
    void startGame();
    void sendTime(QString);  // отображает прошедшее временя
    void sendStep(QString);  // отображает количество шагов
    void moveStep(int, int); // сдвигает надпись с шагами при достижении с 9 - 10 шагов
    void currentRecords(int); // отправляет форме набранный рекорд

public slots:
    void tick();
    void restart();

protected slots:
    void setPosition(QKeyEvent *event);

private:
    MyColor currentColor{ (MyColor) 1 };  // текущий цвет
    int currentPosCol{1}; //текущее положение
    int currentPosRow{0};
    int nCol_{0};         // размер формы на текущем уовне
    int nRow_{0};
    MyColor winColor_;    // цвет для победы
    void takeStand(int iCol = 1, int iRow = 0);  // метод для перехода на заданное место
    int sumStep{0};       // подсчет ходов
    bool running{0};      // игра началась
    bool banPress{0};     // блокировка клавитуры
    int sec_{0};          // прошедшее время
    int min_{0};
    void winEnd(int state);  // выиграл или проиграл
    MyColorCell** familyCells_{nullptr}; // указатель на массив кружков поля
    void BlendColor(MyColorCell* receiver);  // встает на заданный кружок и смешивает цвета по правилам игры

};

#endif // MYRUNNINGCELL_H
