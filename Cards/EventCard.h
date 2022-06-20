//
// Created by Elad on 08/06/2022.
//

#ifndef MTMCHKIN_EVENTCARD_H
#define MTMCHKIN_EVENTCARD_H
#include "Card.h"

class EventCard : public Card {

protected:
    //Default value to be used for event
    static const int DEFAULT_EVENT_VALUE = 10;
public:
    /*
     * C'tor for EventCard
     *
     * @param name - the name of the card.
     * returns - a new instance of EventCard
     */
    explicit EventCard(std::string name): Card(name){}

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~EventCard() override = default;
    EventCard(const EventCard& other) = default;
    EventCard& operator=(const EventCard& other) = default;
};


#endif //MTMCHKIN_EVENTCARD_H
