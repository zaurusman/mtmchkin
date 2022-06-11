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

public:
    Fighter(std::string name);

    int getAttackStrength() const override;

    std::string getJob() const override;

};


#endif //MTMCHKIN_FIGHTER_H
