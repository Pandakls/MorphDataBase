#include "item.h"
//Utils
#include "GadToolKit.h"

Item::Item(){}

Item Item::randomItem(){};

Item Item::randomItemAtPrice(int price){
    Item item = randomItem();
    float ratioPrice = (float)item.getPrice/(float)price;
    while (ratioPrice < 0.9 && ratioPrice> 1.1){
        Item = randomItem();
        ratioPrice = (float)item.getPrice/(float)price;
    }
    return item;
}

Item Item::randomItemUnderPrice(int maxPrice){
    Item item = randomItem();
    while (item.getPrice() > maxPrice){
        Item = randomItem();
    }
    return item;
}
