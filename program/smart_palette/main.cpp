#include "beginner.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Beginner w;
    w.show();

    return a.exec();
}
