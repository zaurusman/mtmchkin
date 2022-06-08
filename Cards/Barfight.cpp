#include "Barfight.h"

//
// Created by Elad on 08/06/2022.
//

Barfight::Barfight():Card("Barfight") {}

void Barfight::applyEncounter(Player& player) const
{
    Fighter* testPlayer = dynamic_cast<Fighter*>(&player);
    if (testPlayer != nullptr){
        player.damage(Barfight::DAMAGE);
    }
}

