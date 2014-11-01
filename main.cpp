//Qt
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QGridLayout>

//Threading
#include <pthread.h>

//World Data & Animation
#include "controler/world.h"
#include "controler/worldcontroler.h"

//Utils
#include "GadToolKit.h"

WorldControler wc;

void* animateWorld(void *arg){
    float time = 0;
    float waitingTime = 0.05;

    while (true){
        wc.animate(time);
        time += waitingTime;
        secSleep(waitingTime);
    }
   (void)arg;
    pthread_exit(NULL);
    return NULL;
}

int main(int argc, char *argv[])
{
    //Creation of world and worldcontroler
    World *world = new World();
    wc = WorldControler(world);

    //Creation of window & widgets
    QApplication a(argc, argv);
    MainWindow mw;
    mw.setWorld(world);
    mw.show();

    //Animate world
    pthread_t mainThread;
    if(pthread_create(&mainThread, NULL, animateWorld, NULL) == -1) {
        perror("pthread_create");
    }

    //Get user event on window
    return a.exec();
}
