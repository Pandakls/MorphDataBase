#ifndef ENTITY_H
#define ENTITY_H

//Utils
#include "GadToolKit.h"

class Entity
{
public:
    Entity();
    //Getters
    inline std::string getFile(){return imageFileName;}
    inline QSize getSize(){return size;}
    inline QPoint getPos(){return pos;}
    //Setters
    inline void setPos(QPoint p){pos = p;}
protected:
    QPoint pos;
    QSize size;
    std::string imageFileName;
};

#endif // ENTITY_H
