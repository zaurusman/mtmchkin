//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_VAMPIRE_H
#define MTMCHKIN_VAMPIRE_H
#include "BattleCard.h"

class Vampire : public BattleCard{
public:
    Vampire();
    ~Vampire()=default;
    void applyEncounter(Player &player) const override;
private:
    static const int VAMPIRE_FORCE =10;
    static const int VAMPIRE_LOOT = 2;
    static const int VAMPIRE_LOSS = 10;
    static const int VAMPIRE_UNBUFF = 1;

};


#endif //MTMCHKIN_VAMPIRE_H
