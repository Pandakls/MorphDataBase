#include "weapon.h"
#include <fstream>

Weapon::Weapon(): Item("Weapon",0,""), power(0), range(1)
{
}

Weapon::Weapon(std::string n, int p, std::string d): Item(n,p,d), power(0), range(1)
{
}

Weapon Weapon::randomWeapon(){
    Weapon w = Weapon();
    int price = 0;
    w.setPrice(price);
    w.loadRandomType();
    w.addPower();
    for (int i=0; i< w.getPower() ; i++){
        w += w.loadRandomWeaponBuff();
    }
    w.setName(w.getName() + ", " + iTos(w.getDd1()) + "d" + iTos(w.getDd2()));
    w.setName(w.getName() + (w.getRange() != 1 ? + ", " + iTos(w.getRange()) + "m" : "") );
    return w;
}

void Weapon::loadRandomType(){
    std::string fileName;
    if (random(0,1) == 0){
        fileName = "../resources/items/weaponMeleeType.txt";
        std::ifstream file(fileName.c_str());
        std::string n,d1,d2,c,p,prob;
        if (!file){
            std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
        }else if(!file.fail()){
            std::string line;
            float rSelection = random(0.0f,1.0f);
            float sumP = 0;
            while (sumP < rSelection && getline( file, line )){
                std::stringstream iss(line);
                getline (iss, n, ',');
                getline (iss, d1, 'd');
                getline (iss, d2, '-');
                getline (iss, c, 'C');
                getline (iss, p, 'k');
                getline (iss, prob, 'p');
                sumP += sTof(prob);
            }
            cc = "cc" + c;
            price = sToi(p);
            dd1 = sToi(d1);
            dd2 = sToi(d2);
            name = n;
        }else{
            std::cout << "Fichier non lisible : " << fileName <<"\n";
        }
        file.close();
    }else{
        fileName = "../resources/items/weaponRangeType.txt";
        std::ifstream file(fileName.c_str());
        std::string n,d1,d2,c,p,po,prob;
        if (!file){
            std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
        }else if(!file.fail()){
            std::string line;
            float rSelection = random(0.0f,1.0f);
            float sumP = 0;
            while (sumP < rSelection && getline( file, line )){
                std::stringstream iss(line);
                getline (iss, n, ',');
                getline (iss, d1, 'd');
                getline (iss, d2, '-');
                getline (iss, c, 'C');
                getline (iss, po, 'm');
                getline (iss, p, 'k');
                getline (iss, prob, 'p');
                sumP += sTof(prob);
            }
            cc = "cc" + c;
            price = sToi(p);
            range = sToi(po);
            dd1 = sToi(d1);
            dd2 = sToi(d2);
            name = n;
        }else{
            std::cout << "Fichier non lisible : " << fileName <<"\n";
        }
        file.close();
    }
}

Item Weapon::loadRandomWeaponBuff(){
    std::string filename;
    if (range == 1){
        filename = "../resources/items/weaponMeleeBuff.txt";
    }else{
        filename = "../resources/items/weaponRangeBuff.txt";
    }
    return loadRandomBuff(filename);
}

void Weapon::upgrade(){
    switch (dd1){
    case 1:
        switch(dd2){
        case 4:
            dd2+=2;
            break;
        case 6:
            dd2+=2;
            break;
        case 8:
            dd2+=2;
            break;
        case 10:
            dd2+=2;
            break;
        case 12:
            dd1+=1;
            dd2-=4;
            break;
        default:
            break;
        }
        break;
    case 2:
        switch(dd2){
        case 4:
            dd2+=2;
            break;
        case 6:
            dd2+=2;
            break;
        case 8:
            dd1+=1;
            dd2-=2;
            break;
        case 10:
            dd2+=2;
            break;
        case 12:
            dd1+=1;
            dd2-=2;
            break;
        default:
            break;
        }
        break;
    case 3 :
        switch(dd2){
        case 6:
            dd1-=1;
            dd2+=4;
            break;
        case 10:
            dd2+=2;
            break;
        case 12:
            dd1+=3;
            dd2-=6;
            break;
        default:
            break;
        }
        break;
    case 5:
        switch(dd2){
        case 6:
            dd1-=1;
            dd2+=4;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Weapon::upgradeRange(){
    range +=5;
}
