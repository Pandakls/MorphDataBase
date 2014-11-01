#ifndef CHARACTER_H
#define CHARACTER_H

#include "stats.h"

//Utils
#include "GadToolKit.h"

//Spells
#include "../ability/spell.h"

//Masteries
#include "../masteries/mastery.h"

//Parent class Entity
#include "entity.h"

class Character : public Entity
{
public:
    Character();
    Character(QPoint p, QSize s, std::string fileName, int lvl) ;
    static Character randomCharacter();

protected:
    std::string name;
    int level;
    Stats stats;
    std::vector<Spell> spells;
    std::vector<Mastery> masteries;
};

#endif // CHARACTER_H
