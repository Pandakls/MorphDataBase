#include "jewel.h"
#include <fstream>

Jewel::Jewel() : Item("Jewel",0,""), power(0)
{
}

Jewel Jewel::randomJewel(){
    Jewel j = Jewel();
    int price = 0;
    j.setPrice(price);
    j.loadRandomType();
    j.addPower();
    for (int i=0; i< j.getPower() ; i++){
        j += loadRandomJewelBuff();
    }
    return j;
}

void Jewel::loadRandomType(){
    std::string fileName = "../resources/items/jewelType.txt";
    std::ifstream file(fileName.c_str());
    std::string t,p;
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
        std::stringstream iss(line);
        getline (iss, t, ',');
        getline (iss, p, 'p');

        power = sToi(p);
        name = t;
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

