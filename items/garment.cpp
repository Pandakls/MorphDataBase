#include "garment.h"
#include <fstream>

Garment::Garment() : Item("Garment",0,""), power(0)
{
}

Garment Garment::randomGarment(){
    Garment g = Garment();
    int price = 0;
    g.setPrice(price);
    g.loadRandomType();
    g.addPower();
    for (int i=0; i< g.getPower() ; i++){
        g += loadRandomGarmentBuff();
    }
    return g;
}

void Garment::loadRandomType(){
    std::string fileName = "../resources/items/garmentType.txt";
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

Item Garment::loadRandomGarmentBuff(){
        std::string filename = "../resources/items/nonWeaponBuffs.txt";
//        std::string filename = "nonWeaponBuffs.txt";
    return loadRandomBuff(filename);
}
