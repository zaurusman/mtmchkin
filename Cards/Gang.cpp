//
// Created by Yotam on 19/06/2022.
//

#include "Gang.h"

Gang::Gang():
BattleCard(GANG_STAT, GANG_STAT, GANG_STAT,"Gang"),
m_monsters(std::vector<std::unique_ptr<BattleCard>>())
{}

void Gang::applyEncounter(Player &player) const
{
    bool lost = false;
    for (std::unique_ptr<BattleCard>const &card : m_monsters)
    {
        if(lost)
        {
            card->onLoss(player);
            card->printWinLose(!lost, player.getName());
        }
        else
        {
            lost = card->applyEncounterAsGang(player);
            if(lost){
                card->printWinLose(!lost, player.getName());
            }
        }
    }
    if(!lost){
        player.levelUp();
       this->printWinLose(!lost, player.getName());
    }
}

void Gang::addMonster(BattleCard& card){
    std::unique_ptr<BattleCard> cardPtr(&card);
    m_monsters.push_back(std::move(cardPtr));
}


int Gang::getSize() const
{
    return m_monsters.size();
}

