#include <fstream>

//To parse a directory
#include "dirent.h"

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
            return Item("Gold", price, "");
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
    Item i = randomItemAtPrice(treasureValue/2);
    treasureValue -= i.getPrice();
    items.push_back(i);
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
    for (int i=0;i<nbArticle;i++){
        Armor a = Armor::randomArmor();
        items.push_back(a);
    }
    res += "\nForgeron (Armures) : " + iTos(nbArticle) + " articles.\n";
    res += itemSort(items, maxPrice);
    items.clear();

    nbArticle = random(nbMin, nbMax);
    for (int i=0;i<nbArticle;i++){
        Weapon a = Weapon::randomWeapon();
        items.push_back(a);
    }
    res += "\nForgeron (Armes) : " + iTos(nbArticle) + " articles.\n";
    res += itemSort(items, maxPrice);
    items.clear();

    nbArticle = random(nbMin, nbMax);
    for (int i=0;i<nbArticle;i++){
        Jewel j = Jewel::randomJewel();
        items.push_back(j);
    }
    res += "\nBijoutier : " + iTos(nbArticle) + " articles.\n";
    res += itemSort(items, maxPrice);
    items.clear();

    nbArticle = random(nbMin, nbMax);
    for (int i=0;i<nbArticle;i++){
        Garment g = Garment::randomGarment();
        items.push_back(g);
    }
    res += "\nTailleur : " + iTos(nbArticle) + " articles.\n";
    res += itemSort(items, maxPrice);
    items.clear();

    std::vector<Item> pots;
    std::vector<int> qties;
    nbArticle = random(nbMin, nbMax);
    for (int i=0;i<nbArticle;i++){
        Potion p = Potion::randomPotion();
        pots.push_back( p);
        qties.push_back(random(1,7) );
    }
    while(pots.size() > 0){
        Item save = pots[0];
        int qty = qties[0];
        pots.erase(pots.begin());
        qties.erase(qties.begin());
        for(unsigned i=0; i<pots.size()-1;i++){
            if(i>=pots.size()){break;}
            if (pots[i].getDesc() == save.getDesc()){
                qty += qties[i];
                pots.erase(pots.begin()+ i);
                qties.erase(qties.begin() + i);
                i-=1;
            }
        }
        Item p = Item(save.getName(), save.getPrice(), save.getDesc() + " (" + iTos(qty) + " in stock)");
        items.push_back(p);
    }
    res += "\nAlchimiste : " + iTos(items.size()) + " articles.\n";
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
    //Tri des items par prix (tri nul n²)
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

std::string Item::basics(){
    std::string res = "Items de Base : \n";
    DIR* rep = opendir("../resources/items/");
    if ( rep == NULL){
        std::cout << "Impossible de lister le répertoire" << std::endl;
    }else{
        struct dirent * ent;
        //Parse resources/masteries
        while ( (ent = readdir(rep)) != NULL)
        {
            std::string fileName = (std::string)(ent->d_name);
            if (fileName != "." && fileName != ".."){
                fileName = "../resources/items/" + fileName;
                //Add it to res
                res += loadItemsFromFile(fileName) + "\n";
            }
        }
        closedir(rep);
    }
    return res;
}

std::string Item::loadItemsFromFile(std::string fileName){
    std::ifstream file(fileName.c_str());
    std::string d = fileName + "\n";

    if (!file){
        std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
    }else if(!file.fail()){
        std::string line;
        while( getline(file, line)){
            d += line + "\n";
        }
    }else{
        std::cout << "Fichier non lisible : " << fileName <<"\n";
    }
    return d;
}
