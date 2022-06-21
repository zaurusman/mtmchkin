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
            decision = getDecision(line);
            cost = applyDecision(decision, player);
            inputValid = true;
        }
        catch (const std::invalid_argument& e){
            printInvalidInput();
        }
    }
    printMerchantSummary(std::cout,player.getName(), decision, cost);
}

int Merchant::applyDecision(int decision, Player &player)
{
    int cost=0;
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
            throw InvalidMerchantInput();
        }
    }
    return cost;
}

int Merchant::getDecision(std::string line) {
    const std::string numbers("0123456789");
    if(line.find_first_not_of(numbers) == std::string::npos){
        return std::stoi(line);
    }
    else{
        throw InvalidMerchantInput();
    }
}


