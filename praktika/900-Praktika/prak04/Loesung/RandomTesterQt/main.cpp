#include "randomtester.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RandomTester w;
    w.show();

    return a.exec();
}
