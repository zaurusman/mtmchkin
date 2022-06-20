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


void BattleCard::applyEncounter(Player& player) const
{
    if(player.getAttackStrength()>=this->m_force)
    {
        printWinLose(true ,player.getName());
        player.addCoins(m_loot);
        player.levelUp();
    } else
    {
        printWinLose(false ,player.getName());
        onLoss(player);
    }
}

void BattleCard::onLoss(Player& player) const
{
    if(m_loss==INFINITE_DAMAGE)//is Dragon
    {
        player.damage(player.getHP());
    }
    else {
        player.damage(m_loss);
    }
}

bool BattleCard::applyEncounterAsGang(Player& player) const{
    if(player.getAttackStrength()>=this->m_force)
    {
        player.addCoins(m_loot);
        return false;
    } else
    {
        onLoss(player);
        return true;
    }
}

void BattleCard::printWinLose(bool win, const std::string& name) const{
    if (win){
        printWinBattle(name,this->getName());
    }
    else{
        printLossBattle(name, this->getName());
    }
}

void BattleCard::getInfoStream(std::ostream &outStream) const {
    bool isDragon = m_loss == BattleCard::INFINITE_DAMAGE;
    printCardDetails(outStream, this->getName());
    printMonsterDetails(outStream, m_force, m_loss, m_loot, isDragon);
    printEndOfCardDetails(outStream);
}

