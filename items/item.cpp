#include <fstream>

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
    std::vector <Item> items;
    int treasureValue = price;
    std::string res = "";
    while (treasureValue > 0.07*price){
        Item i = randomItemUnderPrice(treasureValue);
        treasureValue -= i.getPrice();
        items.push_back(i);
    }
    int minPrice = 0;
    int nextMin =price;
    while(minPrice<price){
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
        nextMin = price;

    }
    return res + "Remaining : " + iTos(treasureValue) + "k\n";
}

Item Item::loadRandomBuff(std::string fileName){
    Item b = Item("", 0, "Buff", "");

    std::ifstream file(fileName.c_str());
    std::string p,d,prob;

    if (!file){
        std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
    }else if(!file.fail()){
        std::string line;
        float rSelection = random(0.0f,1.0f);
        float sumP = 0;
        while ( sumP < rSelection && getline(file, line)){
            //Skip if start with # & blank lines
            while (line.size() == 0 || line[0] == '#'){
                getline(file, line);
            }
                std::stringstream iss(line);
                getline (iss, d, ',');
                getline (iss, p, 'k');
                getline (iss, prob, 'p');
                sumP += sTof(prob);
        }
        b.price = sToi(p);
        b.description = ", " + d;
    }else{
        std::cout << "Fichier non lisible : " << fileName <<"\n";
    }
    file.close();
    return b;
}

void Item::operator+=(Item b){
    name +=  b.getName();
    price += b.getPrice();
    description += b.getDesc();
}

int Item::randomPower(int initPow){
    float rand = random(0.0f,100.0f);
    float add = 100.0f;
    float prob = 0.0f;
    int power = initPow;
    while (prob < rand && power < 10){
        add /=2.0f;
        prob += add;
        power ++;
    }
    return power;
}
