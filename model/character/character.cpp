#include "character.h"
//To parse a directory
#include "dirent.h"

Character::Character() : Entity()
{
}

Character::Character(QPoint p, QSize s, std::string fileName, int lvl) :
    Entity(p, s, fileName),
    level(lvl),
    stats(),
    spells(),
    masteries(){
}

Character Character::randomCharacter(){

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
                  return Character(QPoint(random(1,1000),random(1,500)), QSize(random(10,30),random(10,30)), fileName, 1);
              }
          }
          closedir(rep);
       }
       return Character();
}
