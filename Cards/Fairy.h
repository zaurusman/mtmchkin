//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_FAIRY_H
#define MTMCHKIN_FAIRY_H


#include "Card.h"

class Fairy : public Card{
public:
    Fairy();
    ~Fairy()=default;
    void applyEncounter(Player& player) const override;

private:
    static const int INCREMENT = 10;
};



#endif //MTMCHKIN_FAIRY_H
