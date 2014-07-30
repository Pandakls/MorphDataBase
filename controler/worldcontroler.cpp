#include "worldcontroler.h"
#include "math.h"

WorldControler::WorldControler(){}

WorldControler::WorldControler(World *w) : world(w){

}

void WorldControler::animate(float time){
    for (unsigned i= 0; i< world->getEntities().size();i++){
        Entity e = world->getEntities().at(i);
        int x = e.getPos().x() + (int) (50.0f * cos(time));
        int y = e.getPos().y() + (int) (50.0f * sin(time));
        world->getEntities().at(i).setPos(QPoint(x,y));
    }
}
