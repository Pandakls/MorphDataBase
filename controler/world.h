#ifndef WORLD_H
#define WORLD_H

//Utils
#include "GadToolKit.h"

//Model : World filling
#include "model/entities/character.h"
#include "model/entities/monster.h"
#include "model/entities/clique.h"

#define NB_MAX_ENTITY 30

class World
{
public:
    World();
    //Getter
    inline std::vector<Entity> getEntities(){return entities;}
    inline void setMonsterPos(int i, QPoint p){entities.at(i).setPos(p);}
    void addMonster(Monster m);
    void live(float time);

private :
    int width;
    int height;
    std::vector<Clique> cliques;
    std::vector<Entity> entities;
};

#endif // WORLD_H
