#include <QtGui/QApplication>

#include "picalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    picalc w;
    w.show();

    return a.exec();
}
