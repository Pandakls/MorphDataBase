#include "world.h"

World::World() : width(1100), height(550)
{
    for (int i=0; i<NB_MAX_ENTITY/5; i++){
        Monster m = Monster::randomMonster();
        addMonster(m);
    }
}

void World::live(float /*time*/){
    for (unsigned i= 0; i< cliques.size();i++){
        cliques.at(i).live(width, height);
    }
}

void World::addMonster(Monster m){
    Clique c;
    c.addMonster(m);
    cliques.push_back(c);
    entities.push_back(m);
}
