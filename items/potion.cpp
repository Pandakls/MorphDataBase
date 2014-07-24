#include "potion.h"

Potion::Potion(): Item("",0,"Potion","")
{
}

Potion Potion::randomPotion(){
    Potion p = Potion();
    int price = random(0,100);
    p.setPrice(price);
    return p;
}
