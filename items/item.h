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

    //General random stuff about items
    static Item randomItem();
    static Item randomItemAtPrice(int price);
    static Item randomItemUnderPrice(int maxPrice);
    static std::string randomTreasure(int price);
    static Item loadRandomBuff(std::string fileName);
    static int randomPower(int initPow);

    // += operator between items
    void operator+=(Item b);

    //Getters
    inline int getPrice(){return price;}
    inline std::string getName(){return name;}
    inline std::string getDesc(){return description;}    
    inline std::string toString(){
        return iTos(price) +"k : " + type + ", " + name + description + ".\n";
    }

    //Setters
    inline void setName(std::string n){name = n;}
    inline void setPrice(int p){price = p;}
    inline void setDescription(std::string d){description = d;}

protected:
    std::string name;
    int price;
    std::string type;
    std::string description;

};

#endif // ITEM_H
