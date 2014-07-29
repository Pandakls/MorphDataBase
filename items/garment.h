#ifndef GARMENT_H
#define GARMENT_H

//Utils
#include "GadToolKit.h"

#include "item.h"

class Garment : public Item
{
public:
    Garment();
    static Garment randomGarment();
    //Getter & Setter
    inline int getPower(){return power;}
    inline void addPower(){power = randomPower(power);}
private:
    int power;
    void loadRandomType();
    static Item loadRandomGarmentBuff();
};

#endif // GARMENT_H
