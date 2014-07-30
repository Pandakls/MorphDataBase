#ifndef WORLD_H
#define WORLD_H

//Utils
#include "GadToolKit.h"

class World
{
public:
    World();
    inline QPoint getPos(){return pos;}
    inline void setPos(QPoint p){pos = p;}

private :
    QPoint pos;
};

#endif // WORLD_H
