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
    //Generator
    void slotDiceGen();
    void slotItemGen();
    //DataBase
    void slotMasteries();
    //Navigation
    void slotStackedWidgetNext();
    void slotStackedWidgetPrev();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
