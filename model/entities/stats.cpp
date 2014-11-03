#include "stats.h"


Stats::Stats(int lvl, Vocation v) :
     For(dice(10)+dice(10)+13),
     dFor(1),
     Dex(dice(10)+dice(10)+13),
     dDex(1),
     Esp(dice(10)+dice(10)+13),
     dEsp(1),
     Sav(dice(10)+dice(10)+13),
     dSav(1),
     Sgf(dice(10)+dice(10)+13),
     dSgf(1),
     Vit(dice(10)+dice(10)+13),
     dVit(1){
    for(int i=0; i<lvl-1; i++){
        levelUp(v);
    }
}

std::string Stats::toString(){
    std::string res = "Stats:\n";
    res += "FOR: " + iTos(For) + " (D" + iTos(dFor) + ")\n";
    res += "DEX: " + iTos(Dex) + " (D" + iTos(dDex) + ")\n";
    res += "ESP: " + iTos(Esp) + " (D" + iTos(dEsp) + ")\n";
    res += "SAV: " + iTos(Sav) + " (D" + iTos(dSav) + ")\t(SP="+iTos(Sav/2)+")\n";
    res += "SGF: " + iTos(Sgf) + " (D" + iTos(dSgf) + ")\n";
    res += "VIT: " + iTos(Vit) + " (D" + iTos(dVit) + ")\t(HP="+iTos(Vit*2)+")\n";
    return res;
}

void Stats::levelUp(Vocation v){
    int pointsChar = 6;
    //Deboost
    //Debrid
    //Boost
    switch(v){
    case Tank: //ESP -, SGF-, For +, Dex +, SAV +, VIT ++
        if(Esp>10){Esp--;pointsChar++;}
        if(Sgf>10){Sgf--;pointsChar++;}
        For++;Dex++;Sav++; pointsChar -= 3;
        while(pointsChar > dVit){
            pointsChar -=dVit;
            dVit++;
        }
        Vit += pointsChar;
        break;
    case Melee: //ESP -, SGF-, For ++, Dex +, VIT +
        if(Esp>10){Esp--;pointsChar++;}
        if(Sgf>10){Sgf--;pointsChar++;}
        Dex++;Vit++; pointsChar -= 2;
        while(pointsChar > dFor){
            pointsChar -=dFor;
            dFor++;
        }
        For += pointsChar;
        break;
    case Shooter: //ESP -, For -, SGF ++, Sav/Dex +, VIT +
        if(Esp>10){Esp--;pointsChar++;}
        if(For>10){For--;pointsChar++;}
        Vit++; pointsChar --;
        if(Dex>Sav){Sav++;}else{Dex++;}
        pointsChar --;
        while(pointsChar > dSgf){
            pointsChar -=dSgf;
            dSgf++;
        }
        Sgf += pointsChar;
        break;
    case Magus: //ESP ++, Sav++, For -, SGF -, VIT ++
        if(Sgf>10){Sgf--;pointsChar++;}
        if(For>10){For--;pointsChar++;}
        Vit++; pointsChar --;
        while(pointsChar > dSav + dEsp){
            if(dSav < dEsp){pointsChar -=dSav;dSav++;}
            else{pointsChar -=dEsp;dEsp++;}
        }
        Sav += pointsChar/2;
        Esp += pointsChar - pointsChar/2;
        break;
    case MeleeMagus: //ESP +, Sav+, For ++, SGF -, Vit+
        if(Sgf>10){Sgf--;pointsChar++;}
        Vit++; pointsChar --;
        Sav++; pointsChar --;
        Esp++; pointsChar --;
        while(pointsChar > dFor){
            pointsChar -=dFor;
            dFor++;
        }
        For += pointsChar;
        break;
    case ShooterMagus://ESP +, Sav+, For -, SGF ++, Vit+
        if(For>10){For--;pointsChar++;}
        Vit++; pointsChar --;
        Sav++; pointsChar --;
        Esp++; pointsChar --;
        while(pointsChar > dSgf){
            pointsChar -=dSgf;
            dSgf++;
        }
        Sgf += pointsChar;
        break;
    case TankMagus://ESP +, Sav+, Dex+, For -, SGF -, Vit++
        if(For>10){For--;pointsChar++;}
        if(Sgf>10){Sgf--;pointsChar++;}
        Dex++; pointsChar --;
        Esp++; pointsChar --;
        Sav++; pointsChar --;
        while(pointsChar > dVit){
            pointsChar -=dVit;
            dVit++;
        }
        Vit += pointsChar;
        break;
    case Crafter://ESP ++, Sav++, Dex-, For -, SGF -
        if(For>10){For--;pointsChar++;}
        if(Dex>10){Dex--;pointsChar++;}
        if(Sgf>10){Sgf--;pointsChar++;}
        while(pointsChar > dSav + dEsp){
            if(dSav < dEsp){pointsChar -=dSav;dSav++;}
            else{pointsChar -=dEsp;dEsp++;}
        }
        Sav += pointsChar/2;
        Esp += pointsChar - pointsChar/2;
        break;
    case TankShooter://ESP -, SGF+, For -, Dex +, SAV +, VIT ++
        if(Esp>10){Esp--;pointsChar++;}
        if(For>10){For--;pointsChar++;}
        Sgf++;Dex++;Sav++; pointsChar -= 3;
        while(pointsChar > dVit){
            pointsChar -=dVit;
            dVit++;
        }
        Vit += pointsChar;
        break;
    default: //Tout +1
        For++;Dex++;Esp++;Sav++;Sgf++;Vit++;
    }
}

Stats::Vocation Stats::randomVocation(std::string desc)
{
    if(desc.find("Optimus") != std::string::npos){  //0123
        return (Vocation)(dice(4)-1);
    }
    if(dice(3) == 1){
        if(desc.find("Creation") != std::string::npos ||
                desc.find("Runes") != std::string::npos){
            return (Vocation)(8);
        }
    }
    if(desc.find("SpellCaster") != std::string::npos){ //76
        return (Vocation)(dice(2)+5);
    }
    if(desc.find("Polyvalent") != std::string::npos){ //01234567
        return (Vocation)(dice(8)-1);
    }
    return (Vocation)(dice(9)-1);
}
