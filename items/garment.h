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
};

#endif // GARMENT_H
