//
// Created by Yotam on 08/06/2022.
//

#include "Fairy.h"

Fairy::Fairy():Card(CardType::Heal,"Fairy")
{}

void Fairy::applyEncounter(Player& player) const
{
    if(player.getClass()==PlayerClass::Wizard)
    {
        player.heal(INCREMENT);
    }
}