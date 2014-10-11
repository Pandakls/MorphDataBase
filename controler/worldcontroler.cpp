#include "worldcontroler.h"
#include "math.h"

WorldControler::WorldControler(){}

WorldControler::WorldControler(World *w) : world(w){
}

void WorldControler::animate(float time){
    world->live(time);
    if(time - (int) time < 0.0001){
        world->addEntity(Character::randomCharacter());
    }
}
