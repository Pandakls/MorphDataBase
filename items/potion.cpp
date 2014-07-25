#include "potion.h"
#include <fstream>

Potion::Potion(): Item("",0,"Fiole","")
{
}

Potion Potion::randomPotion(){
    Potion pot = Potion();

    std::string fileName("../resources/items/potionType.txt");
    std::ifstream file(fileName.c_str());
    std::string p,d,prob;

    if (!file){
        std::cout << "Impossible d'ouvrir le fichier :" << fileName << std::endl;
    }else if(!file.fail()){
        std::string line;
        float rSelection = random(0.0f,1.0f);
        float sumP = 0;
        while ( sumP < rSelection && getline(file, line)){
            //Skip if start with # & blank lines
            while (line.size() == 0 || line[0] == '#'){
                getline(file, line);
            }
                std::stringstream iss(line);
                getline (iss, d, ',');
                getline (iss, p, 'k');
                getline (iss, prob, 'p');
                sumP += sTof(prob);
        }
        pot.setPrice(sToi(p));
        pot.setDescription(d);
    }else{
        std::cout << "Fichier non lisible : " << fileName <<"\n";
    }
    file.close();
    return pot;
}
