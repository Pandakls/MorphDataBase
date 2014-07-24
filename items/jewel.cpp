#include "jewel.h"

Jewel::Jewel() : Item("",0,"Jewel","")
{
}

Jewel Jewel::randomJewel(){
    Jewel j = Jewel();
    int price = random(0,1000);
    j.setPrice(price);
    return j;
}
