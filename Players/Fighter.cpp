//
// Created by Yotam on 07/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(std::string name): Player(name){}

int Fighter::getAttackStrength() const
{
    return (2*Player::getAttackStrength() - Player::getLevel());
}

std::string Fighter::getJob() const {
    return "Fighter";
}
