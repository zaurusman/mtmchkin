//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_FAIRY_H
#define MTMCHKIN_FAIRY_H


#include "EventCard.h"

class Fairy : public EventCard{
public:
    Fairy();
    ~Fairy() = default;
    void applyEncounter(Player& player) const override;

private:
    static const int HEAL_VALUE = EventCard::DEFAULT_EVENT_VALUE;
};



#endif //MTMCHKIN_FAIRY_H
