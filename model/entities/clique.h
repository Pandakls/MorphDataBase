#ifndef CLIQUE_H
#define CLIQUE_H

#include "stats.h"

//Utils
#include "GadToolKit.h"

//Parent class Entity
#include "entity.h"

#include "monster.h"

class Clique : public Entity
{
public:
    Clique();
    inline void addMonster(Monster m){monsters.push_back(m);}
    void live(int width, int height);
private:
    std::vector<Monster> monsters;
};

#endif // CLIQUE_H
