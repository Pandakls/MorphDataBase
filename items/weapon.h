#ifndef WEAPON_H
#define WEAPON_H

//Utils
#include "GadToolKit.h"

#include "item.h"

class Weapon : public Item
{
public:
    Weapon();
    static Weapon randomWeapon();
};

#endif // WEAPON_H
