#ifndef BUFF_H
#define BUFF_H

#include <fstream>

//Utils
#include "GadToolKit.h"
#include "item.h"

inline Item insertBuff(int price, std::string desc){

    if (desc.find("FOR") != std::string::npos ||
            desc.find("SGF") != std::string::npos ||
            desc.find("ESP") != std::string::npos ||
            desc.find("SAV") != std::string::npos ||
            desc.find("DEX") != std::string::npos ||
            desc.find("Cast") != std::string::npos ||
            desc.find("Melee") != std::string::npos ||
            desc.find("Shot") != std::string::npos ||
            desc.find("Reflex") != std::string::npos ||
            desc.find("Mental") != std::string::npos){
        int qty = Item::randomPower(0);
        price *= qty;
        desc += " +" + iTos(qty);
    }else if (desc.find("VIT") != std::string::npos){
        int qty = Item::randomPower(0)*2;
        price *= qty;
        desc += " +" + iTos(qty);
    }else if (desc.find("DMG") != std::string::npos){
        switch(random(1,3)){
        case 1:
            desc = "1d6 ";
            price = (int) (((float)(price))*3.5/4.5);
            break;
        case 2:
            desc = "+1d8 ";
            break;
        case 3:
            desc = "+1d10 ";
            price = (int) (((float)(price))*5.5/4.5);
            break;
        default:
            desc = "+1d6 ";
            price = (int) (((float)(price))*3.5/4.5);
            break;
        }
        switch(random(1,6)){
        case 1:
            desc += "dmg de foudre";
            break;
        case 2:
            desc += "dmg de glace";
            break;
        case 3:
            desc += "dmg de terre";
            break;
        case 4:
            desc += "dmg de feu";
            break;
        case 5:
            desc += "dmg d'air";
            break;
        case 6:
            desc += "dmg telekinesiques";
            break;
        default:
            desc += "dmg magiques";
            break;
        }
    }else if (desc.find("Ability") != std::string::npos){
        switch(random(1,30)){
        case 1:
            desc = "Acrobatie/Saut";
            break;
        case 2:
            desc = "Art de la magie";
            break;
        case 3:
            desc = "Con. de la magie";
            break;
        case 4:
            desc = "Bluff";
            break;
        case 5:
            desc = "Con. de la nature";
            break;
        case 6:
            desc = "Crochetage/Desamorçage";
            break;
        case 7:
            desc = "Deguisement/Discretion";
            break;
        case 8:
            desc = "Dep Silencieux";
            break;
        case 9:
            desc = "Diplomacie";
            break;
        case 10:
            desc = "Dressage";
            break;
        case 11:
            desc = "Escalade";
            break;
        case 12:
            desc = "Estimation";
            break;
        case 13:
            desc = "Fouille";
            break;
        case 14:
            desc = "Halterophilie";
            break;
        case 15:
            desc = "Lutte";
            break;
        case 16:
            desc = "Maitrise des cordes";
            break;
        case 17:
            desc = "Marchandage";
            break;
        case 18:
            desc = "Natation";
            break;
        case 19:
            desc = "Perception visuelle";
            break;
        case 20:
            desc = "Perception auditive";
            break;
        case 21:
            desc = "Perception Olfactive";
            break;
        case 22:
            desc = "Survie/Pistage";
            break;
        case 23:
            desc = "Psychologie";
            break;
        case 24:
            desc = "Res à l'alcool";
            break;
        case 25:
            desc = "Res à la torture";
            break;
        case 26:
            desc = "Medecine";
            break;
        case 27:
            desc = "Vol à la tire";
            break;
        default:
            desc = "Bricolage/Métier";
            break;
        }
        int qty = Item::randomPower(2);
        price *= qty;
        desc += " +" + iTos(qty);
    }else if (desc.find("Range") != std::string::npos){
        Weapon weapon("Buff", price, "");
        weapon.upgradeRange();
        return weapon;
    }else if (desc.find("upgraded") != std::string::npos){
      Weapon weapon("Buff", price, desc);
      weapon.upgrade();
      return weapon;
//    }else if (desc.find("Gift") != std::string::npos){
//    }else if (desc.find("Domain") != std::string::npos){
//    }else if (desc.find("Spell") != std::string::npos){
//    }else if (desc.find("Mastery") != std::string::npos){
    }
    desc = ", " + desc;
    return Item("Buff", price, desc);
}

inline Item randomBuff(std::string fileName){
    Item b = Item();
    std::ifstream file(fileName.c_str());
    std::string p,d,prob;

    if (!file){
        std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
    }else if(!file.fail()){
        std::string line;
        float rSelection = random(0.0f,1.0f);
        float sumP = 0.0f;
        while (sumP < rSelection && getline( file, line )){
                std::stringstream iss(line);
                getline (iss, d, ',');
                getline (iss, p, 'k');
                getline (iss, prob, 'p');
                sumP += sTof(prob);
        }
        b = insertBuff(sToi(p), d);
    }else{
        std::cout << "Fichier non lisible : " << fileName <<"\n";
    }
    file.close();
    return b;
}


#endif // BUFF_H
