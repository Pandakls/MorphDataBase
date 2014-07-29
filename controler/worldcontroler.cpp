#include "worldcontroler.h"



WorldControler::WorldControler()
{
}

void* animateWorld(void *arg){
    std::cout << "THREAD OK" << std::endl;
    (void) arg;
    pthread_exit(NULL);
}

int WorldControler::run(){
    pthread_t mainThread;
    if(pthread_create(&mainThread, NULL, animateWorld, NULL) == -1) {
        perror("pthread_create");
    }
    if (pthread_join(mainThread, NULL)) {
        perror("pthread_join");
    }
}
