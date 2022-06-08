//
// Created by Elad on 08/06/2022.
//

#ifndef MTMCHKIN_EVENTCARD_H
#define MTMCHKIN_EVENTCARD_H
#include "Card.h"

class EventCard : public Card {
public:

    static const int DEFAULT_EVENT_VALUE = 10;

    explicit EventCard(std::string name): Card(name){}
    ~EventCard() = default;
};


#endif //MTMCHKIN_EVENTCARD_H
