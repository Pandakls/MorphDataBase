#include "garment.h"
#include <fstream>

Garment::Garment() : Item("",0,"Garment",""), power(0)
{
}

Garment Garment::randomGarment(){
    Garment g = Garment();
    int price = 0;
    g.setPrice(price);
    g.loadRandomType();
    g.setPower(randomPower(g.getPower()));
    for (int i=0; i< g.getPower() ; i++){
        g += loadRandomGarmentBuff();
    }
    return g;
}

void Garment::loadRandomType(){
    std::string fileName = "../resources/items/garmentType.txt";
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

Item Garment::loadRandomGarmentBuff(){
        std::string filename = "../resources/items/nonWeaponBuffs.txt";
//        std::string filename = "nonWeaponBuffs.txt";
    return loadRandomBuff(filename);
}
