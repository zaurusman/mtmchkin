//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_DRAGON_H
#define MTMCHKIN_DRAGON_H

#include "BattleCard.h"

class Dragon : public BattleCard {

public:
    /*
     * C'tor for Dragon
     * returns - a new instance of Dragon
     */
    Dragon();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Dragon() = default;
    Dragon(const Dragon &other) = default;
    Dragon& operator=(const Dragon &other) = default;

    private:
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_LOSS = BattleCard::INFINITE_DAMAGE;
};


#endif //MTMCHKIN_DRAGON_H
