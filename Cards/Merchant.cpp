//
// Created by Yotam on 08/06/2022.
//

#include "Merchant.h"

Merchant::Merchant():Card("Merchant")
{}

void Merchant::PrintInfo(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player,);
}