#ifndef CHARACTER_H
#define CHARACTER_H

#include "stats.h"

//Utils
#include "GadToolKit.h"

//Spells
#include "../spells/spell.h"

//Masteries
#include "../masteries/mastery.h"

class Character
{
public:
    Character();
protected:
    std::string name;
    int level;
    Stats stats;
    std::vector<Spell> spells;
    std::vector<Mastery> masteries;
};

#endif // CHARACTER_H
