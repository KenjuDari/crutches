#ifndef MYGRIDLAYOUT_H
#define MYGRIDLAYOUT_H

#include <QWidget>
#include <QGridLayout>

class MyGridLayout : public QGridLayout
{
    Q_OBJECT
public:
    explicit MyGridLayout(QWidget *parent = 0);
    void setBaseContentsMargins(int marginLeft,int marginTop, int marginRight,int  marginBottom, int spacingNew);

signals:

public slots:
    void getRatio(double percent);

private:
    int baseLeft_{0};
    int baseTop_{0};
    int baseRight_{0};
    int baseBottom_{0};
    int baseSpacing_{0};
};

#endif // MYGRIDLAYOUT_H
