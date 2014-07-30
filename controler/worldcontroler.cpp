#include "worldcontroler.h"
#include "math.h"

WorldControler::WorldControler(){}

WorldControler::WorldControler(World *w) : world(w){

}

void WorldControler::animate(float time){
    int x = 500 + (int) (50.0f * cos(time));
    int y = 200 + (int) (50.0f * sin(time));
    QPoint pos = QPoint(x,y);
    world->setPos(pos);
}
