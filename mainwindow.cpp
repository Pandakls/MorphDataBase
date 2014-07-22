#include "mainwindow.h"
#include "ui_mainwindow.h"

//Utils
#include "GadToolKit.h"

//Dice Gen
#include "dice/dice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string randy = "";
    for (int i=0; i<50; i++){
        randy += iTos(random(1,50));
        randy += "\n";
    }
    ui->label->setText(QString(randy.c_str()));
    connect(ui->actionDice_gen, SIGNAL(triggered()), this, SLOT(slotDiceGen()));
}

void MainWindow::slotDiceGen(){
    std::string res = diceGen();
    ui->label->setText(QString(res.c_str()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
