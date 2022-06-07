//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_VAMPIRE_H
#define MTMCHKIN_VAMPIRE_H
#include "BattleCard.h"

#define VAMPIREFORCE 10
#define VAMPIRELOOT 2
#define VAMPIRELOSS 10

class Vampire : public virtual BattleCard{
public:
    Vampire();
private:
    static const int VAMPIRE_FORCE =10;
    static const int VAMPIRE_LOOT = 2;
    static const int VAMPIRE_LOSS = 10;
};


#endif //MTMCHKIN_VAMPIRE_H
