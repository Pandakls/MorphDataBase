#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Qt
#include <QMainWindow>

//World Data
#include "controler/world.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setImage();
    ~MainWindow();
    void setWorld(World *w);

public slots:
    //Generator
    void slotDiceGen();
    void slotItemGen();
    void slotTreasureGen();
    void slotCityGen(int nbMin, int nbMax);
    inline void slotCityGentp(){slotCityGen(0,1);}
    inline void slotCityGenp(){slotCityGen(1,4);}
    inline void slotCityGenm(){slotCityGen(5,10);}
    inline void slotCityGeng(){slotCityGen(11,25);}
    inline void slotCityGentg(){slotCityGen(26,50);}
    inline void slotCityGenc(){slotCityGen(51,100);}
    //DataBase
    void slotMasteries();
    //Navigation
    void slotStackedWidgetNext();
    void slotStackedWidgetPrev();

    void animate();
    void animateOnce();

private:
    Ui::MainWindow *ui;
    World *world;
    std::vector<QWidget*> displayedEntities;
};

#endif // MAINWINDOW_H
