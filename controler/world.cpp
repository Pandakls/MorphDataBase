#include "world.h"

World::World() : width(1100), height(550)
{
    Entity e = Entity();
    entities.push_back(e);
    Entity f = Entity();
    f.setPos(QPoint(500,10));
    entities.push_back(f);
}

void World::live(float time){
    for (unsigned i= 0; i< entities.size();i++){
        entities.at(i).live(time);
        if (entities.at(i).getPos().x() < 0 ||
                entities.at(i).getPos().x() > width ||
                entities.at(i).getPos().y() < 0 ||
                entities.at(i).getPos().y() > height){
            entities.at(i).bound(width, height);
        }
    }
}
