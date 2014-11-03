#ifndef STATS_H
#define STATS_H
//Utils
#include "GadToolKit.h"

class Stats
{

public:

    enum Vocation {Melee, Shooter, Tank, TankShooter, MeleeMagus, ShooterMagus, Magus, TankMagus, Crafter};
    Stats(int lvl=1, Vocation v=Tank);
    std::string toString();
    void levelUp(Vocation v);
    static Vocation randomVocation(std::string desc);

protected:
    int For;
    int dFor;
    int Dex;
    int dDex;
    int Esp;
    int dEsp;
    int Sav;
    int dSav;
    int Sgf;
    int dSgf;
    int Vit;
    int dVit;
};

#endif // STATS_H
