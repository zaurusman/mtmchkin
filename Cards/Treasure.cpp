//
// Created by Yotam on 09/06/2022.
//

#include "Treasure.h"

Treasure::Treasure():Card("Treasure")
{}

void Treasure::applyEncounter(Player& player) const
{
    printTreasureMessage();
    player.addCoins(COINS);
}