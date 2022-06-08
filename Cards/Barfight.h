//
// Created by Elad on 08/06/2022.
//

#ifndef MTMCHKIN_BARFIGHT_H
#define MTMCHKIN_BARFIGHT_H


#include "EventCard.h"

class Barfight : public EventCard{
public:

    Barfight();
    ~Barfight() = default;
    void applyEncounter(Player& player) const override;
private:
    static const int DAMAGE = EventCard::DEFAULT_EVENT_VALUE;
};


#endif //MTMCHKIN_BARFIGHT_H
