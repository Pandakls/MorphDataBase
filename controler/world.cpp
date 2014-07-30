#include "world.h"

World::World() : width(1100), height(550)
{
    Entity e = Entity();
    entities.push_back(e);
}
