#include "world.h"

World::World() : width(1100), height(550)
{
    for (int i=0; i<NB_MAX_ENTITY; i++){
        Entity e = Entity();
        entities.push_back(e);
    }
}

void World::live(float time){
    for (unsigned i= 0; i< entities.size();i++){
        entities.at(i).live(time);
        if (entities.at(i).getPos().x() < 0 ||
                entities.at(i).getPos().x() > width ||
                entities.at(i).getPos().y() < -height/2 ||
                entities.at(i).getPos().y() > height/2){
            entities.at(i).bound(width, height);
        }
    }
}
