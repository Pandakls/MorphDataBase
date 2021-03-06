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
#include "model/ability/gift.h"
#include "model/ability/spell.h"

//Number of page displayed
#define NB_PAGE 2

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
{
    //Ajout de la page Qtdesign a la classe mainwindow
    ui->setupUi(this);

    ///////////////////////////////////////////////////////////
    ///Connection des différents boutons aux fonctions associées
    //NAVIGATION
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(slotCloseWindow()));
    connect(ui->actionNext, SIGNAL(triggered()), this, SLOT(slotStackedWidgetNext()));
    connect(ui->actionPrev, SIGNAL(triggered()), this, SLOT(slotStackedWidgetPrev()));
    ui->stackedWidget->setCurrentIndex(0);

    //GENERATION ALEATOIRE
    //dés
    connect(ui->actionDice_gen, SIGNAL(triggered()), this, SLOT(slotDiceGen()));
    //Items en tout genre
    connect(ui->actionItem_Gen, SIGNAL(triggered()), this, SLOT(slotItemGen()));
    //Trésors en tout genre
    connect(ui->actionTreasur_Gen, SIGNAL(triggered()), this, SLOT(slotTreasureGen()));
    //Villes par taille
    connect(ui->actionTaille_tp, SIGNAL(triggered()), this, SLOT(slotCityGentp()));
    connect(ui->actionTaille_p, SIGNAL(triggered()), this, SLOT(slotCityGenp()));
    connect(ui->actionTaille_m, SIGNAL(triggered()), this, SLOT(slotCityGenm()));
    connect(ui->actionTaille_g, SIGNAL(triggered()), this, SLOT(slotCityGeng()));
    connect(ui->actionTaille_tg, SIGNAL(triggered()), this, SLOT(slotCityGentg()));
    connect(ui->actionTaille_c, SIGNAL(triggered()), this, SLOT(slotCityGenc()));
    //Noms
    connect(ui->actionNoun_Gen, SIGNAL(triggered()), this, SLOT(slotNounGen()));
    //Character
    connect(ui->actionPNJ_gen, SIGNAL(triggered()), this, SLOT(slotCharGen()));


    //BASE DE DONNEE
    //Maitrises
    connect(ui->actionMasteries, SIGNAL(triggered()), this, SLOT(slotMasteries()));
    //Items de base (Armes et autres)
    connect(ui->actionItems, SIGNAL(triggered()), this, SLOT(slotItems()));
    //Gifts
    connect(ui->actionGift, SIGNAL(triggered()), this, SLOT(slotGifts()));
    //Spells
    connect(ui->actionSpells, SIGNAL(triggered()), this, SLOT(slotSpells()));

    //JEU
    //Creation et initialisation du monde
    world = new World();
    //Animation du monde
    connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(animateOnce()));
    connect(ui->viewButton, SIGNAL(clicked()), this, SLOT(animate()));
}

void MainWindow::setWorld(World *w){
    world = w;
}



///////////////////////////////////////////////////////////////////////////
///Slot (fonctions des différents boutons)
void MainWindow::slotDiceGen(){
    std::string res = diceGen();
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotItemGen(){
    std::string res = "Random items :\n\n";
    int a = 1;
    res+= "Start Adventure\n";
    for (int i = 1; i< 21; i++){
        res+= "DD" + iTos(i);
        if(i == 20){a=2;}
        res+= " : " + Item::randomItemAtPrice(a*10 * (i-1)).toString();
    }
    a=1;
    res+= "\n\nMid Adventure\n";
    for (int i = 1; i< 21; i++){
        res+= "DD" + iTos(i);
        if(i == 20){a=2;}
        res+= " : " + Item::randomItemAtPrice(a*5 * (i-1)*(i-1)).toString();
    }
    a=1;
    res+= "\n\nEnd Adventure\n";
    for (int i = 1; i< 21; i++){
        res+= "DD" + iTos(i);
        if(i == 20){a=2;}
        res+= " : " + Item::randomItemAtPrice(a*10 * (i-1)*i).toString();
    }
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotTreasureGen(){
    std::string res = "Treasures :\n";
    int n1 = 1;
    int n2 = 1;
    int nTemp;
    for(int i= 1; i<12; i++){
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

void MainWindow::slotNounGen(){
    std::string res = "";
    for (int i=0;i<20;i++){
        res += randomName() + "\n";
        res += "\t\t\t\t"+ randomName() +"\n";
        res += "\t\t\t\t\t\t\t\t" + randomName() +"\n";

    }
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotCharGen(){
    std::string res = "";
    for (int i=0; i<5; i++){
        Character c = Character::randomCharacter(random(1,20));
        res += c.toString();
        res += "\n\n\n\n";
    }
    ui->label->setText(QString(res.c_str()));
}



void MainWindow::slotMasteries(){
    std::string res = Mastery::allMasteries();
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotGifts(){
    std::string res = Gift::allGifts();
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotSpells(){
    std::string res = Spell::allSpells();
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotItems(){
    std::string res = Item::basics();
    ui->label->setText(QString(res.c_str()));
}

void MainWindow::slotCloseWindow(){
    this->close();
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
        if (displayedEntities.size()> i){
            displayedEntities.at(i)->move(e.getPos());
        }else{
//            std::cout << "in else" << std::endl;
//            QWidget *widget = new QWidget;
//            QLabel  *label  = new QLabel;
//            QPixmap *pixmap_img = new QPixmap(e.getFile().c_str());
//            label->setPixmap(*pixmap_img);
//            std::cout << "in else" << std::endl;
//            QGridLayout *gridLayout = new QGridLayout(widget);
//            std::cout << "in else" << std::endl;
//            gridLayout->addWidget(label, 0, 0);
//            std::cout << "in else" << std::endl;
//            widget->setLayout(gridLayout);
//            std::cout << "in else" << std::endl;
//            widget->setSizeIncrement(e.getSize());
//            widget->move(e.getPos());
//            widget->show();
//            displayedEntities.push_back(widget);

            QLabel  *label  = new QLabel;
            QPixmap pixmap(e.getFile().c_str());
            QPixmap scaledPixmap(pixmap.scaled(e.getSize()));
            label->setPixmap(scaledPixmap);
            label->move(e.getPos());
            ui->gridLayout->addWidget(label, 0, 0);
            displayedEntities.push_back(label);
        }
    }
    update();
    repaint();
}

void MainWindow::animate(){
    int count =0;
    while(count<200){
        secSleep(0.05);
        animateOnce();
        count ++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
