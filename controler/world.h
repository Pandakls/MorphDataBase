#ifndef WORLD_H
#define WORLD_H

//Utils
#include "GadToolKit.h"

//Model : World filling
#include "model/entity.h"

class World
{
public:
    World();
    //Getter
    inline std::vector<Entity> getEntities(){return entities;}

private :
    int width;
    int height;
    std::vector<Entity> entities;
};

#endif // WORLD_H
