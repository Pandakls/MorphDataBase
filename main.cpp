//Qt
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QGridLayout>

//Utils
#include "GadToolKit.h"

int main(int argc, char *argv[])
{
    //Initialisation of GadToolKit
    initRandom();
    QApplication a(argc, argv);
    MainWindow w;
    w.setImage();
    w.show();

    return a.exec();
}
