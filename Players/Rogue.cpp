//
// Created by Yotam on 07/06/2022.
//

#include "Rogue.h"

Rogue::Rogue(std::string name, int maxHP, int force): Player(name,maxHP,force)
{}

void Rogue::addCoins(int increment)
{
    Player::addCoins(2*increment);
}

PlayerClass Rogue::getClass() const
{
    return PlayerClass::Rogue;
}