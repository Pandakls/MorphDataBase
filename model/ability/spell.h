#ifndef SPELL_H
#define SPELL_H

//Utils
#include "GadToolKit.h"

class Spell
{
public:
    Spell(std::string n, int lvl, std::string pa, std::string ps, std::string d);
    static std::string allSpells();
    static std::string loadSpells(std::string fileName);
    std::string toString();
private:
    std::string name;
    int lvl;
    std::string PA;
    std::string PS;
    std::string desc;
};

#endif // SPELL_H
