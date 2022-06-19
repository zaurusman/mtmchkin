//
// Created by Elad on 19/06/2022.
//

#include "Factories.h"
BattleCard* Factories::createBattleCardFromStream(std::istream &cardDeckFile, std::string& name, int& lineNumber){
    if (name == "Dragon") {
        return new Dragon();
    }
    if (name == "Goblin") {
        return new Goblin();
    }
    if (name == "Vampire") {
        return new Vampire();
    }
    if (name == "Gang") {
     Gang* newGang = new Gang(cardDeckFile, lineNumber);
     lineNumber += newGang->getSize();
     return newGang;
    }
    throw DeckFileFormatError(lineNumber);
}

std::unique_ptr<Card> Factories::createCardFromStream(std::istream &cardDeckFile, int& lineNumber) {
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
    std::unique_ptr<Card> card (Factories::createBattleCardFromStream(cardDeckFile, name, lineNumber));
    return card;

}

std::unique_ptr<Player> Factories::createPlayer(std::string& name, std::string& job) {
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

