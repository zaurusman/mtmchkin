//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_PITFALL_H
#define MTMCHKIN_PITFALL_H


#include "EventCard.h"

class Pitfall : public EventCard{
public:

    Pitfall();
    ~Pitfall() = default;
    void applyEncounter(Player& player) const override;

private:
    static const int DAMAGE = EventCard::DEFAULT_EVENT_VALUE;
};


#endif //MTMCHKIN_PITFALL_H
