#ifndef ITEM_H
#define ITEM_H

//Utils
#include "GadToolKit.h"

class Item
{

public:
    enum ItemType {armor, garment, jewel, potion, weapon};
    Item();
    Item(std::string n, int p, std::string t, std::string d);
    static Item randomItem();
    static Item randomItemAtPrice(int price);
    static Item randomItemUnderPrice(int maxPrice);
    static std::string randomTreasure(int price);

    inline int getPrice(){return price;}
    inline std::string getName(){return name;}
    inline std::string getDesc(){return description;}

    inline void setName(std::string n){name = n;}
    inline void setPrice(int p){price = p;}
    inline void setDescription(std::string d){description = d;}

    inline std::string toString(){
        return iTos(price) +"k : " + type + ", " + name + ", " + description + ".\n";
    }

protected:
    std::string name;
    int price;
    std::string type;
    std::string description;
};

#endif // ITEM_H
