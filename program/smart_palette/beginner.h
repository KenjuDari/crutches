#ifndef BEGINNER_H
#define BEGINNER_H

#include <QWidget>
#include <QObject>
#include <QTimer>
#include <QTime>
#include "mygridlayout.h"
#include "mycolorcell.h"
#include "myrunningcell.h"



namespace Ui {
class Beginner;
}

class Beginner : public QWidget
{
    Q_OBJECT

public:
    explicit Beginner(QWidget *parent = 0);
    ~Beginner();
     QTimer *tmr;

public slots:
    void loadField(int lvl);  // отрисовка уровня
    void setRecordNow(int n); // запись текущего рекорда за пройденный уровен
    void gameWin(int state);  // настройки для всплывающего окна на игровой странице
    void loadRule();          // смена картинок с правилами по щелчку на них на странице "правила"


signals:
    void changeSizeHeightRatio(double);  // сигнал, отправляющий, на сколько процентов изменился размер окна от базового
    void keypress(QKeyEvent*); // оповещение о нажатии клавиши

private:
    Ui::Beginner *ui;
    MyGridLayout *layoutGame{nullptr}; // лайаут для кружков игрового поля по сетке
    MyColorCell **cells{nullptr};      // массив кружков
    MyRunningCell *runningCell{nullptr};  // ведущий, подсвечивающий текущее положении шага, кружок
    int nLvl{10}; // количество уровней

    int nRow{4};  // переменная, хранящая число строк на загруженном уровне
    int nCol{3};  // ... столбцов ...
    int sizeC{80}; // размер кружков на текущем отрисованном поле
    int spacingC{16}; // расстояние между кружками
    double rationNow{1};  // процент от базового размера окна

    int nRecordNow{0}; // текущий рекорд для пройденного уровня
    int stateGameWindow{3}; //состояние всплывающего окна на игровой странице (по умолчанию закрыто)
    bool clickRule{0}; // переменная для перещелкивания двух картинок на странице "правила"

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
};

#endif // BEGINNER_H
