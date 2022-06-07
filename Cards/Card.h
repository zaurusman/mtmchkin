//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_CARD_H
#define MTMCHKIN_CARD_H


#include <string>
#include "Players/Player.h"
#include "utilities.h"

/*
 *  CardType:
 *  Each card has a type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
enum class CardType {Battle, Buff, Heal, Treasure,Event}; // The type of the Card

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card(CardType type, const CardStats& stats);


    Card(CardType type, std::string cardName);

    virtual /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printInfo() const;


    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */
    Card(): m_effect(CardType::Treasure), m_stats() {}


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;


private:
    std::string m_cardName;
    CardType m_effect;
    CardStats m_stats;

};

#endif //MTMCHKIN_CARD_H
