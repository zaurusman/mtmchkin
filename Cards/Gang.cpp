//
// Created by Yotam on 19/06/2022.
//

#include "Gang.h"

Gang::Gang(std::istream &gangFile,int& lineNumber):
BattleCard(GANG_STAT, GANG_STAT, GANG_STAT,"Gang")
{
    std::string cardName;
    while(getline(gangFile, cardName) && cardName!="EndGang")
    {
        lineNumber++;
        std::unique_ptr<BattleCard> current(std::move
        (Factories::createBattleCardFromStream(gangFile,cardName,++lineNumber)));
        m_monsters.push_back(std::move(current));
    }
    if (cardName!="EndGang"){
        throw BadGangFormat(lineNumber);
    }
}

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


int Gang::getSize() const
{
    return m_monsters.size();
}

