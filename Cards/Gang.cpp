//
// Created by Yotam on 19/06/2022.
//

#include "Gang.h"

Gang::Gang(std::istream &gangFile,int lineNumber):
BattleCard(GANG_STAT, GANG_STAT, GANG_STAT,"Gang")
{
    std::string cardName;
    while(getline(gangFile, cardName) && cardName!="EndGang")
    {
        Card* temp = Factories::createBattleCardFromStream(gangFile,cardName,++lineNumber);
        std::unique_ptr<BattleCard> current (dynamic_cast<BattleCard*>(temp));
        m_monsters.push_back(std::move(current));
    }
}

void Gang::applyEncounter(Player &player) const
{
    int currentlevel = player.getLevel();
    bool lost = false;
    for (std::unique_ptr<BattleCard>const &card : m_monsters)
    {
        if(lost)
        {
            card->onLoss(player);
        }
        else{
            card->applyEncounter(player);
            if (currentlevel < player.getLevel()) {
                player.levelDown();
            }
            else {
                lost = true;
            }
        }
    }
    if(!lost){
        player.levelUp();
    }
}

int Gang::getSize() const
{
    return m_monsters.size();
}