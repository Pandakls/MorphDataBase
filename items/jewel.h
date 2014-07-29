#ifndef JEWEL_H
#define JEWEL_H

//Utils
#include "GadToolKit.h"

#include "item.h"

class Jewel : public Item
{
public:
    Jewel();
    static Jewel randomJewel();
    //Getter & Setter
    inline int getPower(){return power;}
    inline void addPower(){power = randomPower(power);}
private:
    int power;
    void loadRandomType();
    static Item loadRandomJewelBuff();
};

#endif // JEWEL_H
