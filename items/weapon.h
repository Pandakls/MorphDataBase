#ifndef WEAPON_H
#define WEAPON_H

//Utils
#include "GadToolKit.h"

#include "item.h"

class Weapon : public Item
{
public:
    Weapon();
    Weapon(std::string, int, std::string);
    static Weapon randomWeapon();
    //Getter & Setter
    inline int getPower(){return power;}
    inline int getDd1(){return dd1;}
    inline int getDd2(){return dd2;}
    inline int getRange(){return range;}
    inline void addPower(){power = randomPower(power);}
    void upgrade();
    void upgradeRange();

private:
    void loadRandomType();
    Item loadRandomWeaponBuff();

    int power;
    int dd1;
    int dd2;
    int range;
    std::string cc;
};

#endif // WEAPON_H
