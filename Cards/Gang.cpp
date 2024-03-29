//
// Created by Yotam on 19/06/2022.
//

#include "Gang.h"

Gang::Gang(std::istream &gangFile,int& lineNumber):
BattleCard(GANG_STAT, GANG_STAT, GANG_STAT,"Gang"),
m_monsters(std::vector<std::shared_ptr<BattleCard>>())
{
    std::string cardName;
    while(getline(gangFile, cardName) && cardName!="EndGang")
    {
        if(cardName == "Gang"){
            throw BadGangFormat(lineNumber);
        }
        lineNumber++;
        std::shared_ptr<BattleCard> current(std::move
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
    for (std::shared_ptr<BattleCard>const &card : m_monsters)
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

void Gang::getInfoStream(std::ostream &outStream) const{
    outStream << "The gangs all here, introducing:\n";
    std::string name;
    for (std::shared_ptr<BattleCard>const &card : m_monsters){
        name = card->getName();
        outStream << name +"\n";
    }
    outStream << "Good Luck!\n";
}

