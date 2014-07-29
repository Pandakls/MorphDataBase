#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Qt
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
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


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
