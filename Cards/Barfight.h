//
// Created by Elad on 08/06/2022.
//

#ifndef MTMCHKIN_BARFIGHT_H
#define MTMCHKIN_BARFIGHT_H


#include "Card.h"

class Barfight : public Card{
public:

    Barfight();
    ~Barfight() = default;
    void applyEncounter(Player& player) const override;
private:
    static const int DAMAGE = 10;
};


#endif //MTMCHKIN_BARFIGHT_H
