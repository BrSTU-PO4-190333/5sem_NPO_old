#include "gpiq_menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gpiq_menu w;
    w.show();

    return a.exec();
}
