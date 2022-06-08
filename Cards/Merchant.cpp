//
// Created by Yotam on 08/06/2022.
//

#include "Merchant.h"

Merchant::Merchant():Card("Merchant")
{}

void Merchant::printInfo() const //TODO: change it
{}

void Merchant::applyEncounter(Player &player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getcoins());
    int 
}

void Merchant::printInfo(Player& player) const
{

}

