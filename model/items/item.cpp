#include <fstream>

#include "item.h"
#include "jewel.h"
#include "armor.h"
#include "garment.h"
#include "potion.h"
#include "weapon.h"
#include "buff.h"

Item::Item(){
    name = "";
    price = 0;
    description = "";
}

Item::Item(std::string n, int p, std::string d) :
    name(n),
    price (p),
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
    return Item("Caillou", 0, ", completement inutile");
}

Item Item::randomItemAtPrice(int price){
    Item item = randomItem();
    float ratioPrice = (float)item.getPrice()/(float)price;
    int count = 0;
    while (ratioPrice < 0.8 || ratioPrice> 1.2){
        count ++;
        if (count > 200){
            return Item("Caillou", 0, ", completement inutile");
        }
        item = randomItem();
        ratioPrice = (float)item.getPrice()/(float)price;
    }
    return item;
}

Item Item::randomItemUnderPrice(int maxPrice){
    Item item = randomItem();
    int count = 0;
    while (item.getPrice() > maxPrice){
        count ++;
        if (count > 200){
            return Item("Caillou", 0, "completement inutile");
        }
        item = randomItem();
    }
    return item;
}

std::string Item::randomTreasure(int price){
    std::vector <Item> items;
    int treasureValue = price;
    while (treasureValue > 0.1*price){
        Item i = randomItemUnderPrice(treasureValue);
        treasureValue -= i.getPrice();
        items.push_back(i);
    }
    std::string res = itemSort(items, price);
    return res + "Remaining : " + iTos(treasureValue) + "k\n";;
}

std::string Item::randomCity(int nbMin, int nbMax){

    std::vector <Item> items;
    int maxPrice = 55000;

    std::string res = "Ville: :\n";

    int nbArticle = random(nbMin, nbMax);
    res += "\nForgeron (Armures) : " + iTos(nbArticle) + " articles.\n";
    for (int i=0;i<nbArticle;i++){
        Armor a = Armor::randomArmor();
        items.push_back(a);
    }
    res += itemSort(items, maxPrice);
    items.clear();

    nbArticle = random(nbMin, nbMax);
    res += "\nForgeron (Armes) : " + iTos(nbArticle) + " articles.\n";
    for (int i=0;i<nbArticle;i++){
        Weapon a = Weapon::randomWeapon();
        items.push_back(a);
    }
    res += itemSort(items, maxPrice);
    items.clear();

    nbArticle = random(nbMin, nbMax);
    res += "\nBijoutier : " + iTos(nbArticle) + " articles.\n";
    for (int i=0;i<nbArticle;i++){
        Jewel j = Jewel::randomJewel();
        items.push_back(j);
    }
    res += itemSort(items, maxPrice);
    items.clear();

    nbArticle = random(nbMin, nbMax);
    res += "\nTailleur : " + iTos(nbArticle) + " articles.\n";
    for (int i=0;i<nbArticle;i++){
        Garment g = Garment::randomGarment();
        items.push_back(g);
    }
    res += itemSort(items, maxPrice);
    items.clear();

    nbArticle = random(nbMin, nbMax);
    res += "\nAlchimiste : " + iTos(nbArticle) + " articles.\n";
    for (int i=0;i<nbArticle;i++){
        Potion p = Potion::randomPotion();
        p.setDescription(p.getDesc() + " (x" +iTos(random(1,7)) + ")");
        items.push_back(p);
    }
    res += itemSort(items, maxPrice);

    return res;
}

void Item::operator+=(Item b){
    price += b.getPrice();
    description += b.getDesc();
}

int Item::randomPower(int initPower){
    float rand = random(0.0f,100.0f);
    float add = 100.0f;
    float prob = 0.0f;
    int power = initPower;
    while (prob < rand && power < 10){
        add /=2.0f;
        prob += add;
        power ++;
    }
    return power;
}

std::string Item::itemSort(std::vector<Item> items, int maxPrice){
    std::string res = "";
    int minPrice = 0;
    int nextMin = maxPrice;
    while(minPrice<maxPrice){
        for (unsigned i=0; i<items.size(); i++){
            int priceCheck = items[i].getPrice();
            if ( priceCheck == minPrice){
                res += items[i].toString();
            }else if(priceCheck > minPrice){
                if (priceCheck < nextMin){
                    nextMin = priceCheck;
                }
            }
        }
        minPrice = nextMin;
        nextMin = maxPrice;
    }
    return res;
}

Item Item::loadRandomBuff(std::string fileName){
    return randomBuff(fileName);
}
