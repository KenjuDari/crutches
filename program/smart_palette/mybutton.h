#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include "myimage.h"

class MyButton : public MyImage
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = 0);
    explicit MyButton(int nPage = 0, QWidget *parent = 0);
    void setPage(int nPage);

signals:
    void changePage(int); // отправляет число по сщелчку
    void click();

public slots:

private:
    int nPage_;

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
};

#endif // MYBUTTON_H
