#include "monster.h"

//To parse a directory
#include "dirent.h"

Monster::Monster()
{
}

Monster::Monster(QPoint p, QSize s, std::string fileName, int lvl) :
    Entity(p, s, fileName),
    name (randomName()),
    level(lvl),
    stats(),
    aggressivity(random(-1.0f,1.0f)){
}

Monster Monster::randomMonster(){

    DIR* rep = opendir("../resources/images/");
       if ( rep == NULL){
          std::cout << "Impossible de lister le répertoire" << std::endl;
       }else{
          struct dirent * ent;
          //Parse resources/images/
          int randomImg = random(0,5);
          int count = 0;
          while ( (ent = readdir(rep)) != NULL)
          {
              std::string fileName = (std::string)(ent->d_name);
              if (fileName != "." && fileName != ".."){
                count ++;
                fileName = "../resources/images/" + fileName;
              }
              if (count > randomImg){
                  std::cout << "fileName : " << fileName << std::endl;
                  return Monster(QPoint(random(1,1000),random(1,500)), QSize(30,30), fileName, 1);
              }
          }
          closedir(rep);
       }
       return Monster();
}

void Monster::live(std::vector<Monster> /*monsters*/, QPoint cliquePos, int cliqueSize){
        if(cliqueSize == 1){ pos = cliquePos;}
        return;

        direction += QPoint(random(-2,2),random(-2,2));
        //limitation en vitesse
        if(direction.x()>7){direction.setX(5);}
        else if (direction.x()<-7){direction.setX(-5);}
        if(direction.y()>7){direction.setY(5);}
        else if (direction.y()<-7){direction.setY(-5);}
        //on vérifie que le monstre est toujours dans la clique
        if(distance(pos,cliquePos)> cliqueSize*10){
            direction = (cliquePos-pos)*0.5;
        }
        pos += direction;
}
