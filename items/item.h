#ifndef ITEM_H
#define ITEM_H

class Item
{
    enum ItemType (Armor, RangeWeapon, MeleeWeapon, Clothe, Jewel, Potion);

public:
    Item();
    Item randomItem();
    Item randomItemAtPrice(int price);
    Item randomItemUnderPrice(int maxPrice);

    inline int getPrice(){return price;}
    inline std::string getName(){return name;}
    inline std::string getDesc(){return description;}

    inline void setName(std::string n){name = n;}
    inline void setPrice(std::string p){price = p;}
    inline void setDescription(std::string d){description = d;}

private:
    std::string name;
    int price;
    std::string description;
};

#endif // ITEM_H
