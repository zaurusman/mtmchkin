//
// Created by Elad on 19/06/2022.
//
#include "Cards/Card.h"
#include "Cards/Dragon.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Exception.h"
#include <memory>

#ifndef MTMCHKIN_CARDFACTORIES_H
#define MTMCHKIN_CARDFACTORIES_H
namespace Factories {
    std::unique_ptr<Card> createCardByNameFromLine(std::string name, int lineNumber);

    std::unique_ptr<Card> createBattleCardByNameFromLine(std::string name, int lineNumber);
    std::unique_ptr<Player> createPlayer(std::string name, std::string job);
}
#endif //MTMCHKIN_CARDFACTORIES_H
