#include "garment.h"

Garment::Garment() : Item("",0,"Garment","")
{
}

Garment Garment::randomGarment(){
    Garment g = Garment();
    int price = random(0,1000);
    g.setPrice(price);
    return g;
}
