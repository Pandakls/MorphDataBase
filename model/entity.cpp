#include "entity.h"

Entity::Entity() :
    pos(QPoint(100,100)),
    direction(0,0),
    size(20,20),
    imageFileName("../resources/images/test.png"){
}

void Entity::live(float time){
    direction += QPoint(random(-3,3),random(-3,3));
    if(direction.x()>10){direction.setX(8);}
    else if (direction.x()<-10){direction.setX(-8);}
    if(direction.y()>10){direction.setY(8);}
    else if (direction.y()<-10){direction.setY(-8);}

    pos += direction;

}

void Entity::bound(int width, int height){
    pos.setX((pos.x() + width)% width);
    pos.setY((pos.y() + height/2 + height)% height -height/2);
}
