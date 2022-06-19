//
// Created by Yotam on 08/06/2022.
//

#include "Vampire.h"

Vampire::Vampire():
    BattleCard(VAMPIRE_FORCE,VAMPIRE_LOOT,VAMPIRE_LOSS,"Vampire")
{}

void Vampire::onLoss(Player& player) const
{
    this->BattleCard::onLoss(player);
    player.unBuff(VAMPIRE_UNBUFF);
}