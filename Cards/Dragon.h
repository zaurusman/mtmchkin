//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_DRAGON_H
#define MTMCHKIN_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard {

public:
    Dragon();
    ~Dragon() = default;
    private:
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_LOSS = -1;//TODO: change it
};


#endif //MTMCHKIN_DRAGON_H