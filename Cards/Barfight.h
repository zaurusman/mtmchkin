//
// Created by Elad on 08/06/2022.
//

#ifndef MTMCHKIN_BARFIGHT_H
#define MTMCHKIN_BARFIGHT_H


#include "EventCard.h"

class Barfight : public EventCard{
public:
    /*
     * C'tor for Barfight card.
     * returns - a new instance of Barfight
     */
    Barfight();

    /*
     * applies the encounter for the Barfight card:
     * all classes other than fighter are damaged by 10 points.
     * @param player - the player who activated the card.
     * returns
     *          void
     */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */

    ~Barfight() override = default;
    Barfight(const Barfight& other) = default;
    Barfight& operator=(const Barfight& other) = default;
private:
    static const int DAMAGE = EventCard::DEFAULT_EVENT_VALUE;
};


#endif //MTMCHKIN_BARFIGHT_H
