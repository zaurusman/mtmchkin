//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_PITFALL_H
#define MTMCHKIN_PITFALL_H


#include "EventCard.h"

class Pitfall : public EventCard{
public:
    /*
     * C'tor for Pitfall card.
     * returns - a new instance of Pitfall
     */
    Pitfall();

    /*
     * applies the encounter for the Pitfall card:
     * all classes other than rogue are damaged by 10 points.
     * @param player - the player who activated the card.
     * returns
     *          void
     */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Pitfall() = default;
    Pitfall(const Pitfall& other) = default;
    Pitfall& operator=(const Pitfall& other) = default;

private:
    static const int DAMAGE = EventCard::DEFAULT_EVENT_VALUE;
};


#endif //MTMCHKIN_PITFALL_H
