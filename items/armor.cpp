#include "armor.h"
#include <fstream>

Armor::Armor() : Item("Armor",0,""), power(0), physicalArmor(0), magicalArmor(0), universalArmor(0)
{
}

Armor Armor::randomArmor(){
    Armor a = Armor();
    int price = 0;
    a.setPrice(price);
    a.loadRandomType();
    a.addPower();
    for (int i=0; i< a.getPower() ; i++){
        a += loadRandomArmorBuff();
    }
    a.setName(a.getName() + (a.getPhy() > 0 ? ", " + iTos(a.getPhy()) + " Armor(Phy)" : ""));
    a.setName(a.getName() + (a.getMag() > 0 ? ", " + iTos(a.getMag()) + " Armor(Mag)" : ""));
    a.setName(a.getName() + (a.getUni() > 0 ? ", " + iTos(a.getUni()) + " Armor(Uni)" : ""));
    return a;
}

void Armor::loadRandomType(){
    std::string fileName = "../resources/items/armorType.txt";
    std::ifstream file(fileName.c_str());
    if (!file){
        std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
    }else if(!file.fail()){
        std::string line;
        getline( file, line );
        int nType = sToi(line);
        nType = random(1,nType-1);
        while ( getline( file, line ) && nType > 0 ){
            nType --;
        }
        name = line;
        generateArmor();
    }else{
        std::cout << "Fichier non lisible : " << fileName <<"\n";
    }
    file.close();
}

Item Armor::loadRandomArmorBuff(){
        std::string filename = "../resources/items/nonWeaponBuffs.txt";
//        std::string filename = "nonWeaponBuffs.txt";
    return loadRandomBuff(filename);
}

void Armor::generateArmor(){
    float typeArmor = random(0.0f, 1.0f);
    if (typeArmor < 0.05){
        int up = random(1, 100)*10;
        universalArmor += up;
        price += (int) ((float)up*1.4f);
    }else if (typeArmor < 0.75){
        int up = random(1, 100)*10;
        physicalArmor += up;
        price += up;
    }else{
        int up = random(1, 100)*10;
        magicalArmor += up;
        price += (int) ((float)up*1.2f);
    }
}
