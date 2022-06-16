//
// Created by Yotam on 08/06/2022.
//

#include "Merchant.h"

Merchant::Merchant():Card("Merchant")
{}

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    int decision;
    int cost = 0;
    std::string line;
    bool inputValid = false;
    while (!inputValid) {
        getline(std::cin, line);
        try {
            decision = std::stoi(line);
            switch (decision) {
                case Merchant::BUY_POTION : {
                    if (player.pay(POTION_PRICE)) {
                        player.heal(HEAL_AMOUNT);
                        cost = POTION_PRICE;
                    }
                    else {
                        printMerchantInsufficientCoins(std::cout);
                    }
                    break;
                }
                case Merchant::BUY_BUFF : {
                    if (player.pay(BUFF_PRICE)) {
                        player.buff(BUFF_AMOUNT);
                        cost = BUFF_PRICE;
                    }
                    else {
                        printMerchantInsufficientCoins(std::cout);
                    }
                    break;
                }
                case Merchant::DONT_BUY: {
                    break;
                }
                default:{
                    printInvalidInput();
                    continue;
                }
            }
        }
        catch (const std::invalid_argument& e){
            printInvalidInput();
        }
        inputValid = true;
    }
    printMerchantSummary(std::cout,player.getName(), decision, cost);
}


