//
// Created by Elad on 19/06/2022.
//

#include "Factories.h"

std::unique_ptr<Card> Factories::createBattleCardByNameFromLine(std::string name, int lineNumber){
    if(name == "Dragon")
    {
        return std::unique_ptr<Card>(new Dragon());
    }
    if(name == "Goblin")
    {
        return std::unique_ptr<Card>(new Goblin());
    }
    if(name == "Vampire")
    {
        return std::unique_ptr<Card>(new Vampire());
    }
    throw DeckFileFormatError(lineNumber);
}

std::unique_ptr<Card> Factories::createCardByNameFromLine(std::string name, int lineNumber){
    if(name == "Barfight")
    {
        return std::unique_ptr<Card>(new Barfight());
    }
    if(name == "Fairy")
    {
        return std::unique_ptr<Card>(new Fairy());
    }
    if(name == "Merchant")
    {
        return std::unique_ptr<Card>(new Merchant());
    }
    if(name == "Pitfall")
    {
        return std::unique_ptr<Card>(new Pitfall());
    }
    if(name == "Treasure")
    {
        return std::unique_ptr<Card>(new Treasure());
    }
    return Factories::createBattleCardByNameFromLine(name, lineNumber);
}

std::unique_ptr<Player> Factories::createPlayer(std::string name, std::string job){
    if (job == "Fighter") {
        return std::unique_ptr<Player>(new Fighter(name));
    }
    if (job == "Rogue") {
        return std::unique_ptr<Player>(new Rogue(name));
    }
    if (job == "Wizard") {
        return std::unique_ptr<Player>(new Wizard(name));
    }
    throw InvalidClass();
}

