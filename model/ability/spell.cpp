#include "spell.h"
//To parse a directory
#include "dirent.h"
#include <fstream>

Spell::Spell(std::string n, int l, std::string pa,std::string ps,std::string d) :
    name(n),
    lvl(l),
    PA(pa),
    PS(ps),
    desc(d){
}

std::string Spell::allSpells(){

    std::string res = "";

    DIR* rep = opendir("../resources/spells/");
    if ( rep == NULL){
        std::cout << "Impossible de lister le répertoire" << std::endl;
    }else{
        struct dirent * ent;
        //Parse resources/spells
        while ( (ent = readdir(rep)) != NULL)
        {
            std::string fileName = (std::string)(ent->d_name);
            if (fileName != "." && fileName != ".."){
                res += "\n\nDomaine : " + fileName + "\n";
                fileName = "../resources/spells/" + fileName;
                //Add all the related spells to res
                res += loadSpells(fileName) + "\n";
            }
        }
        closedir(rep);
    }
    return res;
}

std::string Spell::toString(){
    return "(lvl:" + iTos(lvl) + ")" + name +", " + PA + "PA, " + PS + "PS, " + desc;
}

std::string Spell::loadSpells(std::string fileName){
    std::ifstream file(fileName.c_str());
    std::string n,l,pa,ps,d = "";
    std::string res = "";
    if (!file){
        std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
    }else if(!file.fail()){
        std::string line;
        while( getline(file, line)){
            std::stringstream iss(line);
            n = "";
            getline (iss, n, ',');
            getline (iss, l, 'L');
            getline (iss, pa, 'A');
            getline (iss, ps, 'S');
            getline (iss, d);
            if (n!= ""){res += "(lvl:" + l + ") " + n +", " + pa + "PA, " + ps + "PS, " + d;}
            res += "\n";
        }
    }else{
        std::cout << "Fichier non lisible : " << fileName <<"\n";
    }

    return res;
}
