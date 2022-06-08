//
// Created by Elad on 08/06/2022.
//

#ifndef MTMCHKIN_EVENTCARD_H
#define MTMCHKIN_EVENTCARD_H
#include "Card.h"

class EventCard : public Card {

protected:
    static const int DEFAULT_EVENT_VALUE = 10;
public:
    explicit EventCard(std::string name): Card(name){}
    ~EventCard() = default;
};


#endif //MTMCHKIN_EVENTCARD_H
