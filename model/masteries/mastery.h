#ifndef MASTERY_H
#define MASTERY_H

//Utils
#include "GadToolKit.h"

//Bonus
#include "masterybonus.h"

class Mastery
{
enum Faction {Aquena, Superbia, OmberTertuo, Centurial, Wild, Renegade};

public:

    static std::string toString(Faction f){
        switch (f){
        case Aquena :
            return "Aquena";
        case Superbia :
            return "Superbia";
        case OmberTertuo :
            return "Omber Tertuo";
        case Centurial :
            return "Centurial";
        case Wild:
            return "Wild";
        default:
            return "Renegade";
        }
    }

    static Faction sToFaction(std::string s){
        if (s.find("Aquena") != std::string::npos){
            return Aquena;
        }else if (s.find("Superbia") != std::string::npos){
            return Superbia;
        }else if (s.find("Omber Tertuo") != std::string::npos){
            return OmberTertuo;
        }else if (s.find("Centurial") != std::string::npos){
            return Centurial;
        }
        return Renegade;
    }

    Mastery(std::string n, Faction f, std::string d);
    static std::string allMasteries();
    static Mastery loadMastery(std::string fileName);
    std::string toString();

protected:
    std::string name;
    Faction faction;
    std::string description;
    std::vector<MasteryBonus> bonus;
};

#endif // MASTERY_H
