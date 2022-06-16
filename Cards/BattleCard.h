//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_BATTLECARD_H
#define MTMCHKIN_BATTLECARD_H


#include "Card.h"

class BattleCard : public Card {

public:
    /*
     * C'tor of Card class
     *
     * @param force - force of the monster
     * @param loot - the loot the monster holds
     * @param loss - the amount of damage given on loss
     * @param name - the name of the card
     * @return
     *      A new instance of BattleCard.
    */
    BattleCard(int force, int loot, int loss, std::string name);

    /*
    * updates a given ostream with BattleCard related info.
    * @return
    *      the updated ostream.
   */
    void getInfoStream(std::ostream &outStream) const override;

    /*
     * applies the encounter for the BattleCard:
     * if the player has enough force he levels up and gets the loot, else he losses health.
     * @param player - the player who activated the card.
     * returns
     *          void
     */
    void applyEncounter(Player &player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~BattleCard() = default;
    BattleCard(const BattleCard&) = default;
    BattleCard& operator=(const BattleCard&) = default;

protected:
    //this const represents instant death
    static const int INFINITE_DAMAGE = -1;
private:
    int m_force;
    int m_loot;
    int m_loss;


};


#endif //MTMCHKIN_BATTLECARD_H
