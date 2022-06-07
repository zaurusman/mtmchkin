//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_GOBLIN_H
#define MTMCHKIN_GOBLIN_H
#include "BattleCard.h"

class Goblin : public virtual BattleCard{
public:
    Goblin();
private:
    static const int GOBLIN_FORCE = 6;
    static const int GOBLIN_LOOT = 2;
    static const int GOBLIN_LOSS = 10;
};


#endif //MTMCHKIN_GOBLIN_H
