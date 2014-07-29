#ifndef POTION_H
#define POTION_H

//Utils
#include "GadToolKit.h"

#include "item.h"

class Potion : public Item
{
public:
    Potion();
    static Potion randomPotion();
};

#endif // POTION_H
