#include "clique.h"

Clique::Clique()
{
}

void Clique::live(int width, int height){

    direction += QPoint(random(-3,3),random(-3,3));
    if(direction.x()>10){direction.setX(8);}
    else if (direction.x()<-10){direction.setX(-8);}
    if(direction.y()>10){direction.setY(8);}
    else if (direction.y()<-10){direction.setY(-8);}

    pos += direction;

    for (unsigned i= 0; i< monsters.size();i++){
        monsters.at(i).live(monsters, pos, monsters.size());
        if (monsters.at(i).getPos().x() < 0 ||
                monsters.at(i).getPos().x() > width ||
                monsters.at(i).getPos().y() < -height/2 ||
                monsters.at(i).getPos().y() > height/2){
            monsters.at(i).bound(width, height);
        }
    }
}
