#include "gift.h"
//To parse a directory
#include "dirent.h"
#include <fstream>

Gift::Gift(std::string n, std::string c, std::string d) :
    name(n),
    cond(c),
    desc(d){
}

std::string Gift::allGifts(){

    std::string res = "";

    DIR* rep = opendir("../resources/gifts/");
    if ( rep == NULL){
        std::cout << "Impossible de lister le répertoire" << std::endl;
    }else{
        struct dirent * ent;
        //Parse resources/gifts
        while ( (ent = readdir(rep)) != NULL)
        {
            std::string fileName = (std::string)(ent->d_name);
            if (fileName != "." && fileName != ".."){
                res += "\n\nGifts : " + fileName + "\n";
                fileName = "../resources/gifts/" + fileName;
                //Add all the related gifts to res
                res += loadGifts(fileName) + "\n";
            }
        }
        closedir(rep);
    }
    return res;
}

std::string Gift::toString(){
    return name +" (req : " + cond + ")" + desc;
}

std::string Gift::loadGifts(std::string fileName){
    std::ifstream file(fileName.c_str());
    std::string n,c,d = "";
    std::string res = "";

    if (!file){
        std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
    }else if(!file.fail()){
        std::string line;
        while( getline(file, line)){
            n = "";
            std::stringstream iss(line);
            getline (iss, n, ',');
            getline (iss, c, 'C');
            getline (iss, d);
            if (n!=""){res += n +" (req : " + c + ")," + d;}
            res += "\n";
        }
    }else{
        std::cout << "Fichier non lisible : " << fileName <<"\n";
    }
    return res;
}
