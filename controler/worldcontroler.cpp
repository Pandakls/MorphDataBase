#include "worldcontroler.h"
#include "math.h"

WorldControler::WorldControler(){}

WorldControler::WorldControler(World *w) : world(w){

}

void WorldControler::animate(float time){
    world->live(time);
}
