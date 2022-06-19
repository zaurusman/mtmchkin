//
// Created by Elad on 19/06/2022.
//
#include "Factories.h"

Card* Factories::createBattleCardByNameFromLine(std::string name, int lineNumber){
    if(name == "Dragon")
    {
        return new Dragon();
    }
    if(name == "Goblin")
    {
        return new Goblin();
    }
    if(name == "Vampire")
    {
        return new Vampire();
    }
    throw DeckFileFormatError(lineNumber);
}

Card* Factories::createCardByNameFromLine(std::string name, int lineNumber){
    if(name == "Barfight")
    {
        return new Barfight;
    }
    if(name == "Fairy")
    {
        return new Fairy();
    }
    if(name == "Merchant")
    {
        return new Merchant();
    }
    if(name == "Pitfall")
    {
        return new Pitfall();
    }
    if(name == "Treasure")
    {
        return new Treasure();
    }
    return Factories::createBattleCardByNameFromLine(name, lineNumber);
}

Player* Factories::createPlayer(std::string name, std::string job){
    if (job == "Fighter") {
        return new Fighter(name);
    }
    if (job == "Rogue") {
        return new Rogue(name);
    }
    if (job == "Wizard") {
        return new Wizard(name);
    }
    throw InvalidClass();
}

