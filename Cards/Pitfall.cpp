//
// Created by Yotam on 08/06/2022.
//

#include "Pitfall.h"
Pitfall::Pitfall():EventCard("Pitfall"){}

void Pitfall::applyEncounter(Player& player) const
{
    Rogue* testPlayer = dynamic_cast<Rogue*>(&player);
    if (testPlayer == nullptr){
        player.damage(Pitfall::DAMAGE);
        printPitfallMessage(false);
    }
    printPitfallMessage(true);
}
