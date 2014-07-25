#include "weapon.h"
#include <fstream>

Weapon::Weapon(): Item("",0,"Weapon",""), power(0)
{
}

Weapon Weapon::randomWeapon(){
    Weapon w = Weapon();
    int price = 0;
    w.setPrice(price);
    w.loadRandomType();
    w.setPower(randomPower(w.getPower()));
    for (int i=0; i< w.getPower() ; i++){
        w += loadRandomWeaponBuff();
    }
    return w;
}

void Weapon::loadRandomType(){
    std::string fileName = "../resources/items/weaponMeleeType.txt";
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

Item Weapon::loadRandomWeaponBuff(){
        std::string filename = "../resources/items/weaponMeleeBuff.txt";
//        std::string filename = "nonWeaponBuffs.txt";
    return loadRandomBuff(filename);
}
