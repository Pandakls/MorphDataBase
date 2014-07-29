//Qt
#include "mainwindow.h"
#include <QApplication>

//Utils
#include "GadToolKit.h"

int main(int argc, char *argv[])
{
    //Initialisation of GadToolKit
    initRandom();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
