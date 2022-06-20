//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_MERCHANT_H
#define MTMCHKIN_MERCHANT_H


#include "Card.h"
#include "../utilities.h"

class Merchant : public Card{
public:
        /*
        * C'tor for Merchant
        * returns - a new instance of Merchant
        */
    Merchant();

    /*
     * applies the encounter for the Merchant card
     * player gets into an interactive chat with the merchant
     * enter:
     * BUY_POTION to buy a potion
     * BUY_BUFF to buy a buff
     * DONT_BUY to buy nothing
     *
     * @param player - the player who activated the card.
     * return
     *       void
     */
    void applyEncounter(Player &player) const override;

    /*
    * Here we are explicitly telling the compiler to use the default methods
   */
    ~Merchant() override = default;
    Merchant(const Merchant &other) = default;
    Merchant& operator=(const Merchant &other) = default;

private:

    /*
     * checks the input of the player for the merchant.
     * if its valid acts accordingly.
     * return:
     * for valid input returns the price of the purchase.
     * for invalid input returns INVALID_INPUT.
     */
    static int applyDecision(int decision, Player &player);

    static const int DONT_BUY = 0;
    static const int BUY_POTION = 1;
    static const int BUY_BUFF = 2;
    static const int POTION_PRICE = 5;
    static const int BUFF_PRICE = 10;
    static const int BUFF_AMOUNT = 1;
    static const int HEAL_AMOUNT = 1;
    static const int INVALID_INPUT =-1;

};


#endif //MTMCHKIN_MERCHANT_H
