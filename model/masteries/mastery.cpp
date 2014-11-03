#include "mastery.h"

//To parse a directory
#include "dirent.h"

#include <fstream>

Mastery::Mastery(std::string n, Faction f, std::string d) :
    name(n),
    faction(f),
    description(d),
    level(1){
}

Mastery::Mastery(std::string n, Faction f, std::string d, int l) :
    name(n),
    faction(f),
    description(d),
    level(l){
}

std::string Mastery::allMasteries(){

    std::string res = "";

    DIR* rep = opendir("../resources/masteries/");
    if ( rep == NULL){
        std::cout << "Impossible de lister le répertoire" << std::endl;
    }else{
        struct dirent * ent;
        //Parse resources/masteries
        while ( (ent = readdir(rep)) != NULL)
        {
            std::string fileName = (std::string)(ent->d_name);
            if (fileName != "." && fileName != ".."){
                fileName = "../resources/masteries/" + fileName;
                //Load the concerned mastery
                Mastery mastery = loadMastery(fileName);
                //Add it to res
                res += mastery.toString() + "\n";
            }
        }
        closedir(rep);
    }
    return res;
}

std::string Mastery::toString(){
    return name + " (" + toString(faction) + ")\n" + description;
}

std::string Mastery::toStringShort(){
    return name + " lvl " + iTos(level);
}

Mastery Mastery::loadMastery(std::string fileName){
    std::ifstream file(fileName.c_str());
    std::string n,f,d = "";

    if (!file){
        std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
    }else if(!file.fail()){
        std::string line;
        getline(file, n);
        getline(file, f);
        while( getline(file, line)){
            d += line + "\n";
        }
        if (d!= ""){ d += "\n";}
    }else{
        std::cout << "Fichier non lisible : " << fileName <<"\n";
    }

    Mastery m(n, sToFaction(f), d);
    return m;
}

Mastery Mastery::randomMastery(bool noEnhanced){
    DIR* rep = opendir("../resources/masteries/");
    if ( rep == NULL){
        std::cout << "Impossible de lister le répertoire" << std::endl;
    }else{
        int nbMasteries = 0;
        struct dirent * ent;
        //Parse resources/masteries
        while ( (ent = readdir(rep)) != NULL)
        {
            nbMasteries++;
        }
        closedir(rep);
        int selectedMastery = dice(nbMasteries);
        rep = opendir("../resources/masteries/");
        nbMasteries = 0;
        while ( (ent = readdir(rep)) != NULL)
        {
            nbMasteries++;
            if (nbMasteries == selectedMastery){
                std::string fileName = (std::string)(ent->d_name);
                if (fileName != "." && fileName != ".."){
                    fileName = "../resources/masteries/" + fileName;
                    //Load the concerned mastery
                    Mastery mastery = loadMastery(fileName);
                    if (noEnhanced && mastery.getDesc().find("Enhanced") != std::string::npos){
                        closedir(rep);
                        return randomMastery(noEnhanced);
                    }
                    closedir(rep);
                    return mastery;
                }
            }
        }
        closedir(rep);
    }
    return Mastery("Humain",Aquena,"Random mastery Failed");
}
