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

class Rogue : public Player {

public:
    Rogue(std::string name);

    void addCoins(int increment) override;
    std::string getJob() const override;
};


#endif //MTMCHKIN_ROGUE_H
