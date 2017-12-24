#include "myimage.h"

const QString MyImage::resource_pictures = ":/pictures/resource/";

MyImage::MyImage(QWidget *parent) : QLabel(parent)
{
    sizeBase_ = QSize(500, 600);
}

void MyImage::setBasePixmap(const QPixmap &pixmap)
{
    sizeBase_ = pixmap.size();
    pixmapBase_ = QPixmap(pixmap);
}

void MyImage::setNewPixmap(const QPixmap& pixmap)
{
    resize(sizeNow_);
    pixmap_ = QPixmap(pixmap);
    setPixmap(pixmap_.scaled(sizeNow_, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MyImage::setPositionBase(int x, int y)
{
    posBase_ = QPoint(x, y);
}


void MyImage::getRatio(double percent)
{
      pixmap_ = pixmapBase_;
      sizeNow_ = QSize ( (int)(sizeBase_.width() * percent), (int) (sizeBase_.height() * percent));
      setNewPixmap(pixmap_.scaled(sizeNow_, Qt::KeepAspectRatio, Qt::SmoothTransformation));
      posNow_ = QPoint(posBase_.x() * percent,posBase_.y() * percent);
      move(posNow_);
}


void MyImage::mouseReleaseEvent(QMouseEvent *event)
{
    emit click();
}
