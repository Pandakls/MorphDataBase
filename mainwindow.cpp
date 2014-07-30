#include "mainwindow.h"
#include "ui_mainwindow.h"

//Utils
#include "GadToolKit.h"

//Dice Gen
#include "dice/dice.h"

//Item Gen
#include "model/items/item.h"

//Data
#include "model/masteries/mastery.h"


//Number of page displayed
#define NB_PAGE 2

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
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
    connect(ui->actionMasteries, SIGNAL(triggered()), this, SLOT(slotMasteries()));

    connect(ui->actionNext, SIGNAL(triggered()), this, SLOT(slotStackedWidgetNext()));
    connect(ui->actionPrev, SIGNAL(triggered()), this, SLOT(slotStackedWidgetPrev()));
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(animateOnce()));
    connect(ui->viewButton, SIGNAL(clicked()), this, SLOT(animate()));

    world = new World();
}

void MainWindow::setWorld(World *w){
    world = w;
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

void MainWindow::slotMasteries(){
    std::string res = Mastery::allMasteries();
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotStackedWidgetNext(){
    ui->stackedWidget->setCurrentIndex( (ui->stackedWidget->currentIndex() + 1) % NB_PAGE );
}

void MainWindow::slotStackedWidgetPrev(){
    ui->stackedWidget->setCurrentIndex( (ui->stackedWidget->currentIndex() - 1 + NB_PAGE) % NB_PAGE );
}

void MainWindow::animateOnce(){
    for (unsigned i = 0; i< world->getEntities().size(); i++){

        Entity e = world->getEntities().at(i);
        std::cout << "here" << std::endl;
        if (displayedEntities.size()> i){
            std::cout << "in if" << std::endl;
            displayedEntities.at(i)->setSizeIncrement(e.getSize());
            displayedEntities.at(i)->move(e.getPos());
        }else{
            std::cout << "in else" << std::endl;
            QWidget *widget;
            QLabel  *label  = new QLabel;
            QPixmap *pixmap_img = new QPixmap(e.getFile().c_str());
            label->setPixmap(*pixmap_img);

            QGridLayout *gridLayout = new QGridLayout(widget);
            gridLayout->addWidget(label, 0, 0);
            widget->setLayout(gridLayout);
            widget->setSizeIncrement(e.getSize());
            widget->move(e.getPos());
            widget->show();
            displayedEntities.push_back(widget);
        }
    }
}

void MainWindow::animate(){
    int count =0;
    while(count<500){
        secSleep(0.05);
        animateOnce();
        update();
        repaint();
        count ++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
