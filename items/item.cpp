#include "item.h"
#include "jewel.h"
#include "armor.h"
#include "garment.h"
#include "potion.h"
#include "weapon.h"

Item::Item(){
    name = "";
    price = 0;
    description = "";
    type = "Item";
}

Item::Item(std::string n, int p, std::string t, std::string d) :
    name(n),
    price (p),
    type(t),
    description(d)
    {}

Item Item::randomItem(){
    ItemType type = ItemType(random(0,4));
    switch (type) {
    case armor:
        return Armor::randomArmor();
        break;
    case garment:
        return Garment::randomGarment();
        break;
    case jewel:
        return Jewel::randomJewel();
        break;
    case potion:
        return Potion::randomPotion();
        break;
    case weapon:
        return Weapon::randomWeapon();
        break;
    default:
        return Item();
        break;
    }
    return Item("Caillou", 1, "Item", "completement inutile");
}

Item Item::randomItemAtPrice(int price){
    Item item = randomItem();
    float ratioPrice = (float)item.getPrice()/(float)price;
    while (ratioPrice < 0.9 || ratioPrice> 1.1){
        item = randomItem();
        ratioPrice = (float)item.getPrice()/(float)price;
    }
    return item;
}

Item Item::randomItemUnderPrice(int maxPrice){
    Item item = randomItem();
    while (item.getPrice() > maxPrice){
        item = randomItem();
    }
    return item;
}

std::string Item::randomTreasure(int price){
    int treasureValue = price;
    std::string res = "";
    while (treasureValue > 0.1*price){
        Item i = randomItemUnderPrice(treasureValue);
        res += i.toString();
        treasureValue -= i.getPrice();
    }
    return res;
}
