#ifndef GIFT_H
#define GIFT_H

//Utils
#include "GadToolKit.h"

class Gift
{
public:
    Gift(std::string n, std::string c, std::string d);
    static std::string allGifts();
    static std::string loadGifts(std::string fileName);
    std::string toString();
private:
    std::string name;
    std::string cond;
    std::string desc;
};

#endif // GIFT_H
