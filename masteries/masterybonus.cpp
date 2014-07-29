#include "masterybonus.h"

MasteryBonus::MasteryBonus(std::string n, std::string d, int l) :
    name(n), description(d), level(l){}

std::string MasteryBonus::toString(){
    return "lvl" + iTos(level) + ", " + name + " : " + description;
}
