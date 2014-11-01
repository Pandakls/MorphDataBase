#ifndef GADGEOM_H
#define GADGEOM_H

#include <QPoint>
#include <QSize>
#include "math.h"

inline float distance(QPoint p1, QPoint p2){
    return sqrt((p1.x()-p2.x())*(p1.x()-p2.x())+
                (p1.y()-p2.y())*(p1.y()-p2.y()));
}

#endif // GADGEOM_H
