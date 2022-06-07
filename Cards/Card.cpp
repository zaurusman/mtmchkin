//
// Created by Elad on 02/05/2022.
//

#include "Card.h"

Card::Card(CardType type, const CardStats &stats, std::string cardName) :
    m_effect(type),
    m_stats(stats),
    m_cardName(cardName)

{}
Card::Card(CardType type, std::string cardName) :
        m_effect(type),
        m_cardName(cardName)

{}

void Card::applyEncounter(Player& player) const
{
    switch (m_effect)
    {
        case CardType::Battle:
        {
            bool win;
            if(player.getAttackStrength()>=m_stats.force)
            {
                player.addCoins(m_stats.loot);
                player.levelUp();
                win = true;
            }
            else
            {
                player.damage(m_stats.hpLossOnDefeat);
                win = false;
            }
            printBattleResult(win);
            break;
        }
        case CardType::Buff:
        {
            if(player.pay(m_stats.cost))
            {
                player.buff(m_stats.buff);
            }
            break;
        }
        case CardType::Heal:
        {
            if(player.pay(m_stats.cost))
            {
                player.heal(m_stats.heal);
            }
            break;
        }
        case CardType::Treasure:
        {
            player.addCoins(m_stats.loot);
            break;
        }
    }
}

void Card::printInfo() const
{
    switch (m_effect)
    {
        case CardType::Battle:
        {
            printBattleCardInfo(m_stats);
            break;
        }
        case CardType::Buff:
        {
            printBuffCardInfo(m_stats);
            break;
        }
        case CardType::Heal:
        {
            printHealCardInfo(m_stats);
            break;
        }
        case CardType::Treasure:
        {
            printTreasureCardInfo(m_stats);
            break;
        }
    }
}