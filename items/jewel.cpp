#include "jewel.h"
#include <fstream>

Jewel::Jewel() : Item("",0,"Jewel",""), power(0)
{
}

Jewel Jewel::randomJewel(){
    Jewel j = Jewel();
    int price = 0;
    j.setPrice(price);
    j.loadRandomType();
    j.setPower(randomPower(j.getPower()));
    for (int i=0; i< j.getPower() ; i++){
        j += loadRandomJewelBuff();
    }
    return j;
}

void Jewel::loadRandomType(){
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

Item Jewel::loadRandomJewelBuff(){
        std::string filename = "../resources/items/nonWeaponBuffs.txt";
//        std::string filename = "nonWeaponBuffs.txt";
    return loadRandomBuff(filename);
}

