//
// Created by Elad on 19/06/2022.
//

#include "Factories.h"
using namespace Factories;

std::unique_ptr<Card> createBattleCardFromStream(std::istream &cardDeckFile, std::string& name, int lineNumber){
    if (name == "Dragon") {
        return std::unique_ptr<Card>(new Dragon());
    }
    if (name == "Goblin") {
        return std::unique_ptr<Card>(new Goblin());
    }
    if (name == "Vampire") {
        return std::unique_ptr<Card>(new Vampire());
    }
    if (name == "Gang") {
     std::unique_ptr<Card> newGang(new Gang(cardDeckFile,lineNumber));
     lineNumber+= newGang.getSize();
     return newGang;
    }
    throw DeckFileFormatError(lineNumber);
}

std::unique_ptr<Card> createCardFromStream(std::istream &cardDeckFile, int lineNumber) {
    std::string name;
    lineNumber++;
    getline(cardDeckFile, name);
    if (name == "Barfight") {
        return std::unique_ptr<Card>(new Barfight());
    }
    if (name == "Fairy") {
        return std::unique_ptr<Card>(new Fairy());
    }
    if (name == "Merchant") {
        return std::unique_ptr<Card>(new Merchant());
    }
    if (name == "Pitfall") {
        return std::unique_ptr<Card>(new Pitfall());
    }
    if (name == "Treasure") {
        return std::unique_ptr<Card>(new Treasure());
    }
    return createBattleCardByNameFromStream(cardDeckFile, name, lineNumber);
}

std::unique_ptr<Player> createPlayer(std::string& name, std::string& job) {
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

