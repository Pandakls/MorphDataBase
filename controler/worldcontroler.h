#ifndef WORLDCONTROLER_H
#define WORLDCONTROLER_H

#include "world.h"

//Utils
#include "GadToolKit.h"

class WorldControler
{
public:
    WorldControler();
    WorldControler(World *w);
    void animate(float time);

private:
    World *world;
};

#endif // WORLDCONTROLER_H
