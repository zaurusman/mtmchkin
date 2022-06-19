//
// Created by Yotam on 08/06/2022.
//

#include "Vampire.h"

Vampire::Vampire():
    BattleCard(VAMPIRE_FORCE,VAMPIRE_LOOT,VAMPIRE_LOSS,"Vampire")
{}

void Vampire::applyEncounter(Player& player) const
{
    BattleCard::applyEncounter(player);
    if(player.getAttackStrength()<VAMPIRE_FORCE)
    {
        onLoss(player);
    }
}
void Vampire::onLoss(Player& player) const
{
    player.unBuff(VAMPIRE_UNBUFF);
}