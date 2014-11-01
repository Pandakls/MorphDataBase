#ifndef MONSTER_H
#define MONSTER_H

#include "stats.h"

//Utils
#include "GadToolKit.h"

//Parent class Entity
#include "entity.h"

class Monster : public Entity
{
public:
    Monster();
    Monster(QPoint p, QSize s, std::string fileName, int lvl) ;
    static Monster randomMonster();
    void live(std::vector<Monster> /*monsters*/, QPoint cliquePos, int cliqueSize);
    inline std::string getName(){return name;}
    inline float getAggro(){return aggressivity;}
private:
    std::string name;
    int level;
    Stats stats;
    float aggressivity;
};

#endif // MONSTER_H
