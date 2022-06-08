//
// Created by Yotam on 08/06/2022.
//

#include "Pitfall.h"
Pitfall::Pitfall():Card("Pitfall"){}

void Pitfall::applyEncounter(Player& player) const
{
    Rogue* testPlayer = dynamic_cast<Rogue*>(&player);
    if (testPlayer == nullptr){
        player.damage(Pitfall::DAMAGE);
    }
}

void Pitfall::getCardDetails(std::ostream &outStream) const {
    printPitfallMessage()
}