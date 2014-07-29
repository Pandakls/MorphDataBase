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
    connect(ui->actionTreasur_Gen, SIGNAL(triggered()), this, SLOT(slotTreasureGen()));

    connect(ui->actionTaille_tp, SIGNAL(triggered()), this, SLOT(slotCityGentp()));
    connect(ui->actionTaille_p, SIGNAL(triggered()), this, SLOT(slotCityGenp()));
    connect(ui->actionTaille_m, SIGNAL(triggered()), this, SLOT(slotCityGenm()));
    connect(ui->actionTaille_g, SIGNAL(triggered()), this, SLOT(slotCityGeng()));
    connect(ui->actionTaille_tg, SIGNAL(triggered()), this, SLOT(slotCityGentg()));
    connect(ui->actionTaille_c, SIGNAL(triggered()), this, SLOT(slotCityGenc()));
}

void MainWindow::slotDiceGen(){
    std::string res = diceGen();
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotItemGen(){
    std::string res = "Random item :\n";
    for (int i = 1; i< 21; i++){
        res+= "DD" + iTos(i) + " : " + Item::randomItemAtPrice(10 * (i-1)*(i-1)).toString();
    }
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotTreasureGen(){
    std::string res = "Treasures :\n";
    int n1 = 1;
    int n2 = 1;
    int nTemp;
    for(int i= 1; i<11; i++){
        res += "\nSize : " + iTos(n2*100)+ "k :\n";
        res += Item::randomTreasure(n2*100) + "\n";
        nTemp = n1;
        n1 = n2 ;
        n2 = nTemp + n2;
    }
    ui->label->setText(QString(res.c_str()));
}
void MainWindow::slotCityGen(int nbMin, int nbMax){
    std::string res = Item::randomCity(nbMin,nbMax);
    ui->label->setText(QString(res.c_str()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
