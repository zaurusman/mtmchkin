//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_MERCHANT_H
#define MTMCHKIN_MERCHANT_H


#include "Card.h"
#include "utilities.h"

class Merchant : public Card{
public:

    Merchant();
    ~Merchant() = default;
    void applyEncounter(Player &player) const;
private:
    static const int DONT_BUY = 0;
    static const int BUY_POTION = 1;
    static const int POTION_PRICE = 5;
    static const int BUFF_PRICE = 10;
    static const int BUY_BUFF = 2;

};


#endif //MTMCHKIN_MERCHANT_H
