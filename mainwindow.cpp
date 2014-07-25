#include "mainwindow.h"
#include "ui_mainwindow.h"

//Utils
#include "GadToolKit.h"

//Dice Gen
#include "dice/dice.h"

//Item Gen
#include "items/item.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionDice_gen, SIGNAL(triggered()), this, SLOT(slotDiceGen()));
    connect(ui->actionItem_Gen, SIGNAL(triggered()), this, SLOT(slotItemGen()));
}

void MainWindow::slotDiceGen(){
    std::string res = diceGen();
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotItemGen(){
    std::string res = "Random item :\n" + Item::randomItem().toString();
    res += "\nRandom item Value = 1000:\n" + Item::randomItemAtPrice(1000).toString();
    res += "\nRandom item Value < 1000:\n" + Item::randomItemUnderPrice(1000).toString();
    res += "\nRandom treasure Value = 10000:\n" + Item::randomTreasure(10000);
    ui->label->setText(QString(res.c_str()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
