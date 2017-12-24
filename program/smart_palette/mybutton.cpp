#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : MyImage(parent)
{

}

MyButton::MyButton(int nPage, QWidget *parent): MyImage(parent)
{
    nPage_ = nPage;
}

void MyButton::setPage(int nPage)
{
    nPage_ = nPage;
}

void MyButton::mousePressEvent(QMouseEvent *event)
{
    QPixmap pixmap = QPixmap(resource_pictures + this->objectName() + "LightPress.png");
    setBasePixmap(pixmap);
    QSize sizeNow = pixmap_.size();
    setNewPixmap(pixmap.scaled(sizeNow.width(), sizeNow.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    emit changePage(nPage_);
    emit click();
}

void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    QPixmap pixmap = QPixmap(resource_pictures + this->objectName() + "Light.png");
    setBasePixmap(pixmap);
    QSize sizeNow = pixmap_.size();
    setNewPixmap(pixmap.scaled(sizeNow.width(), sizeNow.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MyButton::enterEvent(QEvent *event)
{
    QPixmap pixmap = QPixmap(resource_pictures + this->objectName() + "Light.png");
    setBasePixmap(pixmap);
    QSize sizeNow = pixmap_.size();
    setNewPixmap(pixmap.scaled(sizeNow.width(), sizeNow.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MyButton::leaveEvent(QEvent *event)
{
    QPixmap pixmap = QPixmap(resource_pictures + this->objectName() + "Visible.png");
    setBasePixmap(pixmap);
    QSize sizeNow = pixmap_.size();
    setNewPixmap(pixmap.scaled(sizeNow.width(), sizeNow.height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}
