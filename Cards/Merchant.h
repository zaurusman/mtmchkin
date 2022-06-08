//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_MERCHANT_H
#define MTMCHKIN_MERCHANT_H


#include "Card.h"
#include "utilities.h"

class Merchant : public Card{

    Merchant();
    ~Merchant() = default;

    void PrintInfo() const;
};


#endif //MTMCHKIN_MERCHANT_H
