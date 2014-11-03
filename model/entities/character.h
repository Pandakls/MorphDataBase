#ifndef CHARACTER_H
#define CHARACTER_H

#include "stats.h"

//Utils
#include "GadToolKit.h"

//Spells & Gifts
#include "../ability/spell.h"
#include "../ability/gift.h"

//Masteries
#include "../masteries/mastery.h"

//Parent class Entity
#include "entity.h"

class Character : public Entity
{

public:
    Character();
    Character(QPoint p, QSize s, std::string fileName, int lvl);
    Character(int lvl, Mastery m, Stats s);
    static Character randomCharacter();
    static Character randomCharacter(int lvl);
    std::string toString();

protected:
    std::string name;
    int level;
    Stats stats;
    std::vector<Spell> spells;
    std::vector<Mastery> masteries;
    std::vector<Gift> gifts;
    Stats::Vocation vocation;
};

#endif // CHARACTER_H
