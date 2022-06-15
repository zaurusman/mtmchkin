//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_FAIRY_H
#define MTMCHKIN_FAIRY_H


#include "EventCard.h"

class Fairy : public EventCard{
public:
    /*
     * C'tor for Fairy
     * returns - a new instance of Fairy
     */
    Fairy();

    /*
     * applies the encounter for the fairy card:
     * if the player is a wizard he is healed by 10 points.
     * param player - the player that invoked the card.
     * returns
     *          void
     */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fairy() = default;
    Fairy(const Fairy& other) = default;
    Fairy& operator=(const Fairy& other) = default;

private:
    static const int HEAL_VALUE = EventCard::DEFAULT_EVENT_VALUE;
};



#endif //MTMCHKIN_FAIRY_H
