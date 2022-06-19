//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_VAMPIRE_H
#define MTMCHKIN_VAMPIRE_H
#include "BattleCard.h"

class Vampire : public BattleCard{
public:
    /*
     * C'tor for Vampire
     * returns - a new instance of Vampire
     */
    Vampire();

    /*
     *
     * applies the encounter for the Vampire Card
     * if the player has enough force he levels up and gets the loot, else he loses health and force.
     * @param player - the player who activated the card.
     * returns
     *          void
     */
    void applyEncounter(Player &player) const override;

    void onLoss(Player &player) const override;
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Vampire()=default;
    Vampire(const Vampire &other) = default;
    Vampire& operator=(const Vampire &other) = default;
private:

    static const int VAMPIRE_FORCE =10;
    static const int VAMPIRE_LOOT = 2;
    static const int VAMPIRE_LOSS = 10;
    static const int VAMPIRE_UNBUFF = 1;

};


#endif //MTMCHKIN_VAMPIRE_H
