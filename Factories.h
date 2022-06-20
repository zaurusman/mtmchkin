//
// Created by Elad on 19/06/2022.
//
#ifndef MTMCHKIN_CARDFACTORIES_H
#define MTMCHKIN_CARDFACTORIES_H
#include "Cards/Card.h"
#include "Cards/Dragon.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Gang.h"
#include "Exception.h"
#include <memory>
namespace Factories {
    /*
     * creates a card based on a given string
     * @param cardDeckFile - the stream of the card list
     * @param lineNumber - the line the string came from
     * return
     *  pointer to a new instance of card based on the string
     */
    std::unique_ptr<Card> createCardFromStream(std::istream &cardDeckFile, int& lineNumber);

    /*
     * creates a battle card based on a given stream
     * @param cardDeckFile - the stream we read from
     * @param name - the name of the card
     * @param lineNumber - the line the string came from
     * return
     *  pointer to a new instance of card based on the string
     */
    std::unique_ptr<BattleCard> createBattleCardFromStream
            (std::istream &cardDeckFile, std::string& name, int& lineNumber);

    /*
     * creates a player based on 2 given strings
     * @param name - the name of the card
     * @param job - the job of the player
     * return
     *  pointer to a new instance of player based on the string
     */
    std::unique_ptr<Player> createPlayer(std::string& name, std::string& job);
}
#endif //MTMCHKIN_CARDFACTORIES_H
