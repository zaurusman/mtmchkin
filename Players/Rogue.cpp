//
// Created by Yotam on 07/06/2022.
//

#include "Rogue.h"

Rogue::Rogue(std::string name): Player(name) {}

void Rogue::addCoins(int increment)
{
    Player::addCoins(2*increment);
}

std::string Rogue::getJob() const{
    return "Rogue";
}
