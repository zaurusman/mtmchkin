//
// Created by Yotam on 07/06/2022.
//

#include "BattleCard.h"

BattleCard::BattleCard(int force, int loot, int loss, std::string name):
    Card(name),
    m_force(force),
    m_loot(loot),
    m_loss(loss)
{}

