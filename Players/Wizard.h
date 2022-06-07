//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_WIZARD_H
#define MTMCHKIN_WIZARD_H

#include "Player.h"

/* Wizard:
     * Wizard is a type of player:
     * special ability: the effect of a healing card is doubled.
    */

class Wizard : public virtual Player {

    Wizard(std::string name, int maxHP, int force);

    void heal(int increment) override;

    PlayerClass getClass() const override;
};


#endif //MTMCHKIN_WIZARD_H
