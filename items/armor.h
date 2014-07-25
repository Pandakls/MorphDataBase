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
private:
    void loadRandomType();
    static Item loadRandomArmorBuff();
};

#endif // ARMOR_H
