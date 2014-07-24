#include "weapon.h"

Weapon::Weapon(): Item("",0,"Weapon","")
{
}

Weapon Weapon::randomWeapon(){
    Weapon w = Weapon();
    int price = random(0,100);
    w.setPrice(price);
    return w;
}
