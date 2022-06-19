//
// Created by Yotam on 19/06/2022.
//

#include "Gang.h"

Gang::Gang(std::istream &gangFile,int lineNumber):
BattleCard(0,0,0,"Gang")
{
    m_size=0;
    std::string cardName;
    while(getline(gangFile, cardName)&&cardName!="EndGang")
    {
        Card* temp = Factories::createBattleCardFromStream(gangFile,cardName,++lineNumber);
        std::unique_ptr<BattleCard> current(dynamic_cast<BattleCard*>(temp));
        m_monsters.push_back(std::move(current));
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