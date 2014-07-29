#ifndef MASTERYBONUS_H
#define MASTERYBONUS_H

//Utils
#include "GadToolKit.h"

class MasteryBonus
{
public:
    MasteryBonus(std::string n, std::string d, int l);
    std::string toString();

private:
    std::string name;
    std::string description;
    int level;
};

#endif // MASTERYBONUS_H
