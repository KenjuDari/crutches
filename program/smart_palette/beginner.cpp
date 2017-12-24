#include "beginner.h"
#include "ui_beginner.h"

#include <QObject>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QPixmap>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QMessageBox>

#include "myimage.h"
#include "myverticallayout.h"
#include "mybutton.h"
#include "mycolorcell.h"
#include "myrunningcell.h"
#include "mygridlayout.h"
#include "mylabel.h"
#include "mystar.h"


Beginner::Beginner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Beginner)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);

    tmr = new QTimer(this);
    tmr->setInterval(1000);
    tmr->start();


    // Заголовок на главной странице с меню

    ui->title->setText("<font color=red face=Mistral><i>Умная палитра</i></font>");
    ui->title->setMyGeometry(36, 400, 70, 95, 40);
    ui->title->raise();
    ui->title->show();
    //


    // создание кнопок меню с указанием страниц

    MyButton* menuButtonNewGame = new MyButton(1);
    menuButtonNewGame->setObjectName("menuButtonNewGame");
    MyButton* menuButtonLvl = new MyButton(2);
    menuButtonLvl->setObjectName("menuButtonLvl");
    MyButton* menuButtonRules = new MyButton(3);
    menuButtonRules->setObjectName("menuButtonRules");
    MyButton* menuButtonExit = new MyButton(0);
    menuButtonExit->setObjectName("menuButtonExit");
    //


    // добавление кнопок меню в вертикальный лайаут

    ui->background->setLayout(ui->layoutButtonsMenu);
    ui->layoutButtonsMenu->setBaseContentsMargins(120, 130, 120, 50, 30);
    ui->layoutButtonsMenu->addWidget(menuButtonNewGame);
    ui->layoutButtonsMenu->addWidget(menuButtonLvl);
    ui->layoutButtonsMenu->addWidget(menuButtonRules);
    ui->layoutButtonsMenu->addWidget(menuButtonExit);
    //


    // добавление кнопок на странице "уровни"

    MyGridLayout* layoutLevels = new MyGridLayout();
    ui->pageLevels->setLayout(layoutLevels);
    layoutLevels->setBaseContentsMargins(60, 50, 60, 30, 0);

    MyButton** buttonLevels = new MyButton*[nLvl];  // nLvl == 10
    int row(0);
    for (int i(1); i <= nLvl; i++)
    {
        buttonLevels[i-1] = new MyButton(i);
        buttonLevels[i-1]->setObjectName("lvl" + QString::number(i));
        buttonLevels[i-1]->setBasePixmap(QPixmap(":/pictures/resource/lvl" + QString::number(i)+ "Visible.png"));
        layoutLevels->addWidget(buttonLevels[i-1], row, (i-1)%2, Qt::AlignHCenter);
        QObject::connect(buttonLevels[i-1], SIGNAL(changePage(int)), this, SLOT(loadField(int)));
        QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), buttonLevels[i-1], SLOT(getRatio(double)));
        row += (i-1)%2;
    }
    //


    // коннект кнопок по щелчку
    QObject::connect(menuButtonNewGame, SIGNAL(changePage(int)), this, SLOT(loadField(int)));
    QObject::connect(menuButtonLvl, SIGNAL(changePage(int)), ui->pages, SLOT(setCurrentIndex(int)));
    QObject::connect(menuButtonRules, SIGNAL(changePage(int)), ui->pages, SLOT(setCurrentIndex(int)));
    QObject::connect(menuButtonExit, SIGNAL(click()), this, SLOT(close()));

    ui->closeHelp->setPage(3); // закрытие всплывающего окна н игровой странице
    ui->closeHelp2->setPage(0); // закрытие старицы "правила"
    ui->closeHelp2->setPositionBase(460,0);
    QObject::connect(ui->closeHelp, SIGNAL(changePage(int)) , this, SLOT(gameWin(int)));
    QObject::connect(ui->closeHelp2, SIGNAL(changePage(int)), ui->pages, SLOT(setCurrentIndex(int)));
    QObject::connect(ui->backgroundRule, SIGNAL(click()), this,  SLOT(loadRule()));

    ui->star0->setSerialNumber(1);
    ui->star1->setSerialNumber(2);
    ui->star2->setSerialNumber(3);
    ui->buttonMenu->setPage(0);
    ui->buttonHelp->setPage(2);
    QObject::connect(ui->buttonMenu, SIGNAL(changePage(int)), ui->pages, SLOT(setCurrentIndex(int)));
    QObject::connect(ui->buttonHelp, SIGNAL(changePage(int)), this, SLOT(gameWin(int)));
    QObject::connect(ui->buttonNext, SIGNAL(changePage(int)), this, SLOT(loadField(int)));
    //

    //загрузка изображений

    ui->background->setBasePixmap(QPixmap(":/pictures/resource/background.jpg"));
    ui->background2->setBasePixmap(QPixmap(":/pictures/resource/background.jpg"));
    ui->backgroundGame->setBasePixmap(QPixmap(":/pictures/resource/field.png"));
    ui->backgroundRule->setBasePixmap(QPixmap(":/pictures/resource/rules0.png"));
    menuButtonNewGame->setBasePixmap(QPixmap(":/pictures/resource/menuButtonNewGameVisible.png"));
    menuButtonLvl->setBasePixmap(QPixmap(":/pictures/resource/menuButtonLvlVisible.png"));
    menuButtonRules->setBasePixmap(QPixmap(":/pictures/resource/menuButtonRulesVisible.png"));
    menuButtonExit->setBasePixmap(QPixmap(":/pictures/resource/menuButtonExitVisible.png"));
    ui->closeHelp->setBasePixmap(QPixmap(":/pictures/resource/closeHelpVisible.png"));
    ui->closeHelp2->setBasePixmap(QPixmap(":/pictures/resource/closeHelp2Visible.png"));
    ui->buttonHelp->setBasePixmap(QPixmap(":/pictures/resource/buttonHelpVisible.png"));
    ui->buttonRenew->setBasePixmap(QPixmap(":/pictures/resource/buttonRenewVisible.png"));
    ui->buttonMenu->setBasePixmap(QPixmap(":/pictures/resource/buttonMenuVisible.png"));
    ui->buttonNext->setBasePixmap(QPixmap(":/pictures/resource/buttonNextVisible.png"));
    //


    // коннект сохранения пропорций

    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->background, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->background2, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->backgroundGame, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->backgroundRule, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), menuButtonNewGame, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), menuButtonLvl, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), menuButtonRules, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), menuButtonExit, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->winWindow, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->closeHelp, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->closeHelp2, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), layoutLevels, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->title, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->layoutButtonsMenu, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->labelLvl, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->colorWin, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->gameTime, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->closeHelp, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->gameStep, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->buttonHelp, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)),ui-> buttonRenew, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->buttonMenu, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->buttonNext, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->star0, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->star1, SLOT(getRatio(double)));
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), ui->star2, SLOT(getRatio(double)));
    //

    // установка начального положение игры
    ui->pages->setCurrentIndex(0);
    ui->winWindow->hide();

    ui->winWindow->setPositionBase(0,0);
    ui->labelLvl->setMyGeometry(35, 80, 80, 30, 0);
    ui->colorWin->setPositionBase(69, 547);
    ui->gameTime->setMyGeometry(40, 200, 170, 160, 30);
    ui->gameStep->setMyGeometry(32, 100, 100, 234, 525);
    ui->buttonHelp->setPositionBase(170, 10);
    ui->buttonRenew->setPositionBase(270, 10);
    ui->buttonMenu->setPositionBase(370, 10);
    ui->buttonNext->setPositionBase(200,300);
    ui->star0->setPositionBase(55,150);
    ui->star1->setPositionBase(190,150);
    ui->star2->setPositionBase(320,150);
    //

}

Beginner::~Beginner()
{
    delete ui;
}

void Beginner::gameWin(int state)  // встплывающее окно на игровой странице
{

 stateGameWindow = state;
 ui->winWindow->setBasePixmap(QPixmap(":/pictures/resource/finish" + QString::number(stateGameWindow)+ ".png"));
 ui->winWindow->setNewPixmap(QPixmap(":/pictures/resource/finish" + QString::number(stateGameWindow)+ ".png"));

 switch (stateGameWindow) {

 case 0: // конец игры

     ui->winWindow->setPositionBase(40, 200);
     ui->closeHelp->setPositionBase(340,60);
     ui->winWindow->show();
     ui->closeHelp->show();
     ui->buttonNext->hide();
     ui->star0->hide();
     ui->star1->hide();
     ui->star2->hide();
     ui->winWindow->getRatio(rationNow);
     ui->closeHelp->getRatio(rationNow);
     break;

 case 1: // победа
     ui->winWindow->setPositionBase(8, 80);
     ui->closeHelp->setPositionBase(390,70);
     ui->winWindow->show();
     ui->closeHelp->show();
     ui->buttonNext->show();
     ui->star0->show();
     ui->star1->show();
     ui->star2->show();
     ui->winWindow->getRatio(rationNow);
     ui->closeHelp->getRatio(rationNow);
     ui->buttonNext->getRatio(rationNow);
     break;

 case 2: // подсказка
     ui->winWindow->setPositionBase(8, 80);
     ui->closeHelp->setPositionBase(390,70);
     ui->winWindow->show();
     ui->closeHelp->show();
     ui->buttonNext->hide();
     ui->star0->hide();
     ui->star1->hide();
     ui->star2->hide();
     ui->winWindow->getRatio(rationNow);
     ui->closeHelp->getRatio(rationNow);
     break;

 case 3: //закрыть всплывающее окно
     ui->winWindow->hide();
     break;
 }
}

void Beginner::loadField(int lvl)
{

    if (layoutGame != nullptr) {
        delete layoutGame;
    }
    if (runningCell != nullptr) {
        delete runningCell;
    }
    if (cells != nullptr) {
        for (int i(0); i < nRow; i++)
        {
            for (int j(0); j < nCol; j++)
            {
                delete cells[i * nCol + j];
            }
        }
        delete cells;
    }
    //


    // настройки уровней 2 сложностей

    MyColor winColor((MyColor)3);
    if (lvl < 5)
    {
        nRow = 4;
        nCol = 3;
        spacingC = 6;
        sizeC = 80;
    }
    else
    {
        if (lvl <= 10)
        {
            nRow = 5;
            nCol = 4;
            spacingC = 9;
            sizeC = 60;
        }
        else
        {
            QMessageBox::information(this, "Error", "Don't right level");
            return;
        }
    }

    layoutGame = new MyGridLayout();
    ui->backgroundGame->setLayout(layoutGame);
    QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), layoutGame, SLOT(getRatio(double)));
    layoutGame->setBaseContentsMargins(104,174, 104, 88, spacingC);
    //


    // Считывание уровня из файла

    QFile lvlFile (":/text/resource/level.txt");
    if(!lvlFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Don't read file with level");
        return;
    }

    QTextStream stream(&lvlFile);

    while(!stream.atEnd())
    {
        QString str = stream.readLine();
        QStringList lst = str.split(" ");
        if (lst.at(0).toInt() == lvl) // ищем строку с нужным уровнем int lvl
        {
            if ((lst.count() - 2) != nRow * nCol) {
                QMessageBox::information(this, "Error", "Deficiency data or Incorrect number of rows and columns");
                return;
            }

           winColor = (MyColor) lst.at(1).toInt(); // цвет для победы

           // ведущий кружок
           runningCell = new MyRunningCell(QSize(sizeC, sizeC), nCol, nRow, winColor, MyColor::transparent, 1, 0, layoutGame->parentWidget());
           runningCell->raise();           
           QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), runningCell, SLOT(getRatio(double)));
           //

           // Остальные кржки на поле

               cells = new MyColorCell*[nRow * nCol];
               for (int i(0); i < nRow; i++)
               {
                   for (int j(0); j < nCol; j++)
                   {
                       cells[i * nCol + j] = new MyColorCell(QSize(sizeC, sizeC), (MyColor)lst.at(i * nCol + j + 2).toInt(), j, i);
                       layoutGame->addWidget(cells[i * nCol + j], i, j, Qt::AlignHCenter);

                       QObject::connect(this, SIGNAL(changeSizeHeightRatio(double)), cells[i * nCol + j], SLOT(getRatio(double)));

                       QObject::connect(runningCell, SIGNAL(yourColorChange(MyColorCell*,MyColor)), cells[i * nCol + j], SLOT(changeColor(MyColorCell*,MyColor)));
                       QObject::connect(runningCell, SIGNAL(iLeftYou(int,int)), cells[i * nCol + j], SLOT(runningCellLeft(int,int)));

                       QObject::connect(ui->buttonRenew, SIGNAL(click()), runningCell, SLOT(restart()));
                       QObject::connect(ui->buttonMenu, SIGNAL(click()), runningCell, SLOT(restart()));
                       QObject::connect(ui->closeHelp, SIGNAL(click()), runningCell, SLOT(restart()));

                       QObject::connect(runningCell, SIGNAL(currentRecords(int)), ui->star0, SLOT(setActive(int)));
                       QObject::connect(runningCell, SIGNAL(currentRecords(int)), ui->star1, SLOT(setActive(int)));
                       QObject::connect(runningCell, SIGNAL(currentRecords(int)), ui->star2, SLOT(setActive(int)));
                   }
               }              

               QObject::connect(tmr, SIGNAL(timeout()), runningCell, SLOT(tick())); // счетчиков часов

               QObject::connect(this, SIGNAL(keypress(QKeyEvent*)), runningCell, SLOT(setPosition(QKeyEvent*)));              
               QObject::connect(runningCell, SIGNAL(sendTime(QString)), ui->gameTime, SLOT(setText(QString)));
               QObject::connect(runningCell, SIGNAL(sendStep(QString)), ui->gameStep, SLOT(setText(QString)));
               QObject::connect(runningCell, SIGNAL(moveStep(int,int)),ui->gameStep, SLOT(setPos(int,int)));
               QObject::connect(runningCell, SIGNAL(finish(int)), this, SLOT(gameWin(int)));

               runningCell->setFamilyCells(cells);
               runningCell->takeStart();
        }
    }
    lvlFile.flush();
    lvlFile.close();
    //


    //

    ui->labelLvl->setText("<font color=white face=Franklin Gothic>" +QString::number(lvl) + "</font>");
    ui->colorWin->setBasePixmap(QPixmap(QString(":/pictures/resource/purposeC" + QString::number(winColor)+ ".png")));
    ui->gameTime->setText("<font color=red face=Franklin Gothic>00:00</font>");
    ui->gameStep->setText("<font color=black face=Franklin Gothic>0</font>");

    if (lvl != 10) {
       ui->buttonNext->setPage(lvl+1);
    }


    // начальное положение

    gameWin(3); // закрытие всплывающего окна
    ui->pages->setCurrentIndex(1);
    //


    // Перерисовка всех компонентов поля с помощью слота перерисовки по заданному размеру
    QSize sizeNow(size());
    resize(sizeNow.width()+1, sizeNow.height()+1);   // this is not bug this is feature C:
    resize(sizeNow);
    //
}


void Beginner::loadRule()
{
    ui->backgroundRule->setNewPixmap(QPixmap(":/pictures/resource/rules" + QString::number(clickRule) +".png"));
    clickRule = !clickRule;
}


void Beginner::setRecordNow(int n)
{
    nRecordNow = n;
}


void Beginner::resizeEvent(QResizeEvent *event)
{
    resize((int)(event->size().height() * baseSize().width() / baseSize().height()), event->size().height());
    double base = (double) baseSize().height();
    rationNow = (event->size().height() / base);
    emit changeSizeHeightRatio(rationNow);
}


void Beginner::keyPressEvent(QKeyEvent *event)
{
    emit keypress(event);
}
