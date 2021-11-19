#include "mkoq_menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mkoq_menu w;
    w.show();

    return a.exec();
}
