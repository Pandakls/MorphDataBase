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
