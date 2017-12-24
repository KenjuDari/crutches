#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QEvent>
#include <QPoint>

class MyImage : public QLabel
{
    Q_OBJECT
public:
    explicit MyImage(QWidget *parent = 0);
    void setBasePixmap(const QPixmap& pixmap);  // запоминает картинку и ее размер для отрисовки, при изменении размера
    void setNewPixmap(const QPixmap& pixmap);  // изменяет размер в соотношении с текущим состояниям окна
    void setPositionBase(int x, int y);  // перемещает на заданное положение

signals:
   void click();

public slots:
    void getRatio(double percent);

protected:
   static const QString resource_pictures;
   QPixmap pixmap_;  //текущая картинка с правильным размером
   QSize sizeNow_{QSize(0,0)};
   QPoint posNow_{QPoint(0,0)};

   QSize sizeBase_{QSize(0,0)};
   QPixmap pixmapBase_;
   QPoint posBase_{QPoint(0,0)};

   // QWidget interface
protected:
   virtual void mouseReleaseEvent(QMouseEvent *event);
};

#endif // MYIMAGE_H
