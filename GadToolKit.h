#ifndef RANDOMSTUFF_H
#define RANDOMSTUFF_H

#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <sstream>  /* ostringstream */
#include <string>   /* string, stringstream */
#include <assert.h> /* assert */

///////////////
//Random stuffs
//Initialisation
inline void initRandom(){
    srand (time(NULL));
}
//Random int
inline int random(int s, int e){
    return rand() % (e - s + 1) + s;
}
//Random float
inline float random (float s, float e){
    float res = (float)(rand() % 10000) /10000.;
    return res * (e-s)+s;
}
//Random dice
inline int dice (int e){
    return random(1,e);
}

///////////////
//Itoa & Atoi
inline std::string iTos(int i){
    std::ostringstream os;
    os << i;
    return os.str();
}
inline std::string fTos(float f){
    std::ostringstream os;
    os << f;
    return os.str();
}
inline int sToi(std::string s){
    int res;
    std::stringstream str(s);
    assert(str);
    str >> res;
    return res;
}

#endif // RANDOMSTUFF_H
