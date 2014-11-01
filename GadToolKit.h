#ifndef RANDOMSTUFF_H
#define RANDOMSTUFF_H

#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <sstream>  /* ostringstream */
#include <string>   /* string, stringstream */
#include <assert.h> /* assert */
#include <iostream> /* std::cout << std::endl */
#include <vector>   /* vector<> */

#include "GadGeom.h" /*basic geometry lib */

//assert with specific message. Use : ASSERT(cond, msg);

#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
    } while (false)


///////////////
//Random stuffs
//Initialisation
static bool is_random_initialized = false;
static void initializeR(){
    srand (time(NULL));
    is_random_initialized = true;
}

//Random int
inline int random(int s, int e){
    if (!is_random_initialized){initializeR();}
    return rand() % (e - s + 1) + s;
}
//Random float
inline float random (float s, float e){
    if (!is_random_initialized){initializeR();}
    float res = (float)(rand() % 10000) /10000.;
    return res * (e-s)+s;
}

//Random dice
inline int dice (int e){
    return random(1,e);
}
//Random consonne
inline std::string randomCons(){
    std::string cons;
    int R = dice(18);
    int Q = dice(4);

    switch(R) {
    case 1:cons="b";break;
    case 2:cons="c";break;
    case 3: if (Q == 1) cons="j";
        else if (Q == 2) cons="y";
        else cons="h";break;
    case 4:cons="d";break;
    case 5: if (Q == 1) cons="w";
        else if (Q == 2) cons="z";
        else cons ="x"; break;
    case 6:if (Q == 1) cons="ff";
        else cons="f";break;
    case 7:cons="g";break;
    case 8:cons="v";break;
    case 10:cons="k";break;
    case 11:if (Q == 1) cons="ll";
        else cons="l";break;
    case 12:if (Q == 1) cons="mm";
        else cons="m";break;
    case 13:if (Q == 1) cons="nn";
        else cons="n";break;
    case 14:if (Q == 1) cons="ph";
        else cons="p";break;
    case 15:cons="qu";break;
    case 16:if (Q == 1) cons="rr";
        else cons="r";break;
    case 17:cons="s"; break;
    case 18: cons = "t";break;
    case 9:if (Q == 1) cons="sh";
        else if (Q == 2) cons = "ss";
        else cons="th";break;
    }
    return cons;
}
//Random voyelle
inline std::string randomVoy(){
    std::string voy;

    int R = dice(8);
    int Q;
    switch(R) {
    case 1: voy="a";break;
    case 2: voy="e";break;
    case 3: Q = dice(4);
        if(Q != 1) voy="o";
        else voy="y"; break;
    case 4: voy="i";break;
    case 5: Q = dice(4);
        if(Q!=1) voy="u";
        else voy="y"; break;
    case 6: Q = dice(3);
        if(Q==1) voy="ou";
        else if(Q==2) voy="au";
        else voy="eu";break;
    case 7: Q = dice(4);
        if(Q==1) voy="en";
        else if(Q==2) voy="on";
        else if(Q==3) voy = "an";
        else voy = "in"; break;
    case 8: Q = dice(18);
        switch(Q){
        case 1:voy="ö";break;
        case 2:voy="ü";break;
        case 3:voy="ë";break;
        case 4:voy="ï";break;
        case 5:voy="ê";break;
        case 6:voy="è";break;
        case 7:voy="ä";break;
        default: voy="é";break;
        }
        break;
    }
    return voy;
}
//Random name
inline std::string randomName(){
    std::string name = "";
    int nounSize= dice(4);
    bool wasVoy = (dice(2)==1)? true : false;

    for(int i=0; i<nounSize;i++){
        if(dice(10)==1){ wasVoy=!wasVoy;}
        if(wasVoy){
            name += randomCons();
            name +=randomVoy();
        }else{
            name +=randomVoy();
            name += randomCons();
        }
    }
return name;
}

/////////////
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
inline float sTof(std::string s){
    float res;
    std::stringstream str(s);
    assert(str);
    str >> res;
    return res;
}

////////////////////
//sleep redefinition
inline void miliSleep(int milliseconds) // cross-platform sleep function
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end)
    {
    }
}
inline void secSleep(float secondes){
    miliSleep((int)(secondes*1000));
}

#endif // RANDOMSTUFF_H
