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
    inline void setPower(int p){power = p;}
private:
    int power;
    void loadRandomType();
    static Item loadRandomArmorBuff();
};

#endif // ARMOR_H
