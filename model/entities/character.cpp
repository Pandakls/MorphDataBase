#include "character.h"
//To parse a directory
#include "dirent.h"

Character::Character() : Entity()
{
}

Character::Character(QPoint p, QSize s, std::string fileName, int lvl) :
    Entity(p, s, fileName),
    name (randomName() + " " +randomName()),
    level(lvl),
    stats(),
    spells(),
    masteries(),
    gifts(),
    vocation(){
}

Character::Character(int lvl, Mastery m, Stats s) :
    Entity(QPoint(0,0), QSize(0,0), "../resources/masteries/" + m.getName()),
    name (randomName() + " " +randomName()),
    level(lvl),
    stats(s),
    spells(),
    gifts(),
    vocation(){
    masteries.push_back(m);
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

Character Character::randomCharacter(int lvl){
    Mastery m = Mastery::randomMastery(true);
    m.setLvl(lvl);
    Stats::Vocation v = Stats::randomVocation(m.getDesc());
    Stats s(lvl, v);
    Character c(lvl, m, s);
    return c;
}

std::string Character::toString(){
    std::string res = name + " (lvl : " + iTos(level) +")\n";
    if(masteries.size()==0){res += "WARNING EMPTY MASTERIES\n";}
    for(unsigned i =0; i<masteries.size(); i++){
        if (i >0){res += ", ";}
        res += masteries[i].toStringShort();
        if (i==masteries.size()-1){res += "\n";}
    }
    res += stats.toString() + "\n";
    return res;
}
