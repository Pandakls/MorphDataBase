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
};

#endif // JEWEL_H
