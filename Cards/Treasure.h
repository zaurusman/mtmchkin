//
// Created by Yotam on 09/06/2022.
//

#ifndef MTMCHKIN_TREASURE_H
#define MTMCHKIN_TREASURE_H


#include "Card.h"
#include "utilities.h"

class Treasure : public Card {
public:
    Treasure();
    ~Treasure() = default;
    void applyEncounter(Player& player) const override;
private:
    static const int COINS = 10;
};


#endif //MTMCHKIN_TREASURE_H
