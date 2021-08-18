#include "pixeon.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pixeon w;
    w.show();
    return a.exec();
}
