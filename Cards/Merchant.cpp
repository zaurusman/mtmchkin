//
// Created by Yotam on 08/06/2022.
//

#include "Merchant.h"

Merchant::Merchant():Card("Merchant")
{}

void Merchant::printInfo() const //TODO: change it
{}

void Merchant::applyEncounter(Player &player)
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getcoins());
    int desicion;
    bool validInput = false;
    while(!validInput) {
        if (validInput)
        {
            printMerchantInsufficientCoins(std::cout);
        }
        std::cin >> desicion;//TODO: try catch this

        if (desicion == BUY_POTION&&player.pay(POTION_PRICE))
        {
            player.heal(1);
            validInput = true;
        }
        if (desicion == BUY_BUFF&&player.pay(BUFF_PRICE))
        {
            player.buff(1);
            validInput = true;
        }

    }
    printMerchantSummary(std::cout,player.getName(),DONT_BUY,0);//TODO: change this
}


