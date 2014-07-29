#ifndef ARMOR_H
#define ARMOR_H

//Utils
#include "GadToolKit.h"

#include "item.h"

class Armor : public Item
{
public:
    Armor();
    static Armor randomArmor();
    //Getter & Setter
    inline int getPower(){return power;}
    inline void addPower(){power = randomPower(power);}
    inline int getPhy(){return physicalArmor;}
    inline int getMag(){return magicalArmor;}
    inline int getUni(){return universalArmor;}

private:
    void loadRandomType();
    void generateArmor();
    static Item loadRandomArmorBuff();

    int power;
    int physicalArmor;
    int magicalArmor;
    int universalArmor;
};

#endif // ARMOR_H
