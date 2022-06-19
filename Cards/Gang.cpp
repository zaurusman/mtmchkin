//
// Created by Yotam on 19/06/2022.
//

#include "Gang.h"

Gang::Gang(const std::string &gangFile,int lineNumber):
Card("Gang")
{
    m_size=0;
    std::ifstream gangList(gangFile);
    if(!gangList)
    {
        throw DeckFileNotFound();
    }
    std::string cardName;
    while(getline(gangList, cardName)&&cardName!="EndGang")
    {
        m_monsters.push_back(Factories::createBattleCardFromStream(cardName,++lineNumber));
        m_size++;
    }
}

void Gang::applyEncounter(Player &player) const
{
    int gangSize = m_monsters.size();
    int currentlevel = player.getLevel();
    bool lost = false;
    for (std::unique_ptr<BattleCard>const &card:m_monsters)
    {
        if(lost)
        {
            card->onLoss(player);
        }
        else{
            card->applyEncounter(player);
            if (currentlevel < player.getLevel()) {
                player.levelDown();
            } else {
                lost = true;
            }
        }
    }
}

int Gang::getSize() const
{
    return m_size;
}