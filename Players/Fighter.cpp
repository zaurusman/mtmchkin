//
// Created by Yotam on 07/06/2022.
//

#include "Fighter.h"

Fighter::Fighter(std::string name, int maxHP, int force): Player(name,maxHP,force)
{}
int Fighter::getAttackStrength() const
{
    return Player::getAttackStrength() + Player::getAttackStrength() - Player::getLevel();
}

PlayerClass Fighter::getClass() const
{
    return PlayerClass::Fighter;
}