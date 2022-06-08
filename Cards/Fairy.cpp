//
// Created by Yotam on 08/06/2022.
//

#include "Fairy.h"

Fairy::Fairy():EventCard("Fairy") {}

void Fairy::applyEncounter(Player& player) const
{
    Wizard* testPlayer = dynamic_cast<Wizard*>(&player);
    if (testPlayer != nullptr){
        player.heal(Fairy::HEAL_VALUE);
        printFairyMessage(true);
    }
    printFairyMessage(false);
}

void Fairy::getCardDetails(std::ostream &outStream) const {}