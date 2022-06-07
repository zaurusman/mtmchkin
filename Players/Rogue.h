//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_ROGUE_H
#define MTMCHKIN_ROGUE_H

#include "Player.h"

/* Rogue:
     * Rogue is a type of player:
     * special ability: gets 2x coins during the whole game.
    */

class Rogue : public virtual Player {

    Rogue(std::string name, int maxHP, int force);

    void addCoins(int increment) override;

    PlayerClass getClass() const override;
};


#endif //MTMCHKIN_ROGUE_H
