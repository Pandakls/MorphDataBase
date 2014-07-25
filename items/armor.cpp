#include "armor.h"
#include <fstream>

Armor::Armor() : Item("",0,"Armor","")
{
}

Armor Armor::randomArmor(){
    Armor a = Armor();
    int price = random(0,1000);
    a.setPrice(price);
    a.loadRandomType();
    a += loadRandomArmorBuff();
    return a;
}

void Armor::loadRandomType(){
    std::string filename = "../resources/items/armorType.txt";
    std::ifstream file(filename.c_str());
    if (!file.fail()){
        std::string line;
        getline( file, line );
        std::cout << "line [" << line << "]" << std::endl;
        int nType = sToi(line);
        nType = random(1,nType);
        while ( getline( file, line ) && nType > 0 ){
            nType --;
            std::cout << "line [" << line << "]" << std::endl;
        }
        type += line;
    }
    else{
        std::cout << "Fichier inexistant ou non lisible : " << filename <<"\n";
    }
}

Item Armor::loadRandomArmorBuff(){
    std::string filename = "../resources/items/nonWeaponBuffs.txt";
    return loadRandomBuff(filename);
}
