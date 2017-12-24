#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
    explicit MyLabel(int sizeSriftBase, int widthBase, int heightBase, int posX = 0, int posY = 0, QWidget *parent = 0);
    void setMyGeometry (int sizeSriftBase, int widthBase, int heightBase, int posX = 0, int posY = 0);

signals:

public slots:
    void getRatio(double percent);
    void setPos (int posX, int posY);  // перемещает на заданное расстояние от базового положения

private:
    int posX_{0};
    int posY_{0};
    int posXNow_{0};
    int posYNow_{0};
    int widthBase_{30};
    int heightBase_{30};
    int widthNow_{30};
    int heightNow_{30};
    int sizeSriftBase_{16};
};

#endif // MYLABEL_H
