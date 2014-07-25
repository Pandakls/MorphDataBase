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
    //Getter & Setter
    inline int getPower(){return power;}
    inline void setPower(int p){power = p;}
private:
    int power;
    void loadRandomType();
    static Item loadRandomWeaponBuff();
};

#endif // WEAPON_H
