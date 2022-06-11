//
// Created by Yotam on 08/06/2022.
//

#include "Merchant.h"

Merchant::Merchant():Card("Merchant")
{}


void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getcoins());
    int decision=-1;
    while(decision==-1)
    {
        std::cin >> decision;//TODO: try catch this, the file says to use getLine - check about it 

        if (decision == BUY_POTION&&player.pay(POTION_PRICE))
        {
            player.heal(1);
            continue;
        }
        if (decision == BUY_BUFF&&player.pay(BUFF_PRICE))
        {
            player.buff(1);
            continue;
        }
        if(decision==0) {
            continue;
        }
        decision =-1;
        printMerchantInsufficientCoins(std::cout);
    }
    printMerchantSummary(std::cout,player.getName(),decision,POTION_PRICE*decision);
}


