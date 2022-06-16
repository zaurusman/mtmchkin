//
// Created by Yotam on 09/06/2022.
//

#ifndef MTMCHKIN_TREASURE_H
#define MTMCHKIN_TREASURE_H


#include "Card.h"
#include "utilities.h"

class Treasure : public Card {
public:
    /*
     * C'tor for Treasure
     * returns - a new instance of Treasure
     */
    Treasure();

    /*
     * applies the encounter for the Treasure card
     * player gets 10 coins
     * @param player - the player who activated the card.
     * return
     *       void
     */
    void applyEncounter(Player& player) const override;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Treasure() = default;
    Treasure(const Treasure &other) = default;
    Treasure& operator=(const Treasure &other) = default;


private:
    static const int COINS = 10;
};


#endif //MTMCHKIN_TREASURE_H
