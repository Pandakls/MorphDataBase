#ifndef DICE_H
#define DICE_H

//Utils
#include "GadToolKit.h"

#define NB_LAUNCH 10
#define NB_SERIES 2


static std::string makeRow(int diceSize){
    std::string res0 = "";
    std::string res1 = "";
    std::string res2 = "";

    for (int j=0; j<NB_SERIES; j++){
        int sum = 0;
        for (int i=0; i<NB_LAUNCH; i++){
            res0 += iTos(i+1) + "\t";
            int launch = dice(diceSize);
            res1 += iTos(launch) + "\t";
            sum += launch;
            res2 += iTos(sum) + "\t";
        }
        if (j <NB_SERIES-1){
            res0 += "\t";
            res1 += "\t";
            res2 += "\t";
        }
    }
    return iTos(diceSize) + ":\n" + res0 + "\n" + res1 + "\n" + res2 + "\n";
}

inline std::string diceGen(){
    std::string res = "";
    res += makeRow(4) + "\n\n";
    res += makeRow(6) + "\n\n";
    res += makeRow(8) + "\n\n";
    res += makeRow(10) + "\n\n";
    res += makeRow(12) + "\n\n";
    res += makeRow(20) + "\n\n";
    return res;
}



#endif // DICE_H
