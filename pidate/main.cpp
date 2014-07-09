#include <QtGui/QApplication>
#include "pidate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PiDate w;
    w.show();

    return a.exec();
}
