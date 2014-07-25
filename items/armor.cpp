#include "armor.h"
#include <fstream>

Armor::Armor() : Item("",0,"Armor",""), power(0)
{
}

Armor Armor::randomArmor(){
    Armor a = Armor();
    int price = 0;
    a.setPrice(price);
    a.loadRandomType();
    a.setPower(randomPower(a.getPower()));
    for (int i=0; i< a.getPower() ; i++){
        a += loadRandomArmorBuff();
    }
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
        type += line;
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
