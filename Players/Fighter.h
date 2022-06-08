//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_FIGHTER_H
#define MTMCHKIN_FIGHTER_H

#include "Player.h"

/* Fighter:
     * Fighter is a type of player:
     * special ability: attack calculated by: force*2+level
    */

class Fighter :public Player {

    Fighter(std::string name, int maxHP, int force);

    int getAttackStrength() const override;

    PlayerClass getClass() const override;
};


#endif //MTMCHKIN_FIGHTER_H
