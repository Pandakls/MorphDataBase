#include "worldcontroler.h"
#include "math.h"

WorldControler::WorldControler(){}

WorldControler::WorldControler(World *w) : world(w){
}

void WorldControler::animate(float time){
    world->live(time);
    if(time-(int)time < 0.00001 && (int)(time)%10 == 0){
        world->addMonster(Monster::randomMonster());
    }
}
