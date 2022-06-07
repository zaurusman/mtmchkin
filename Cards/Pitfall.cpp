//
// Created by Yotam on 08/06/2022.
//

#include "Pitfall.h"
Pitfall::Pitfall():Card(CardType::Event,"Pitfall")//TODO: delete the card type from every card class.
{}

void Pitfall::applyEncounter(Player& player) const
{
    if(!(player.getClass()==PlayerClass::Rogue))
    {
        player.damage(DAMAGE);
    }
}