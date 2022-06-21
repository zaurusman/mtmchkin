//
// Created by Elad on 19/06/2022.
//

#include "Factories.h"
std::unique_ptr<BattleCard> Factories::createBattleCardFromStream
(std::istream &cardDeckFile, std::string& name, int& lineNumber) {
    if (name == "Dragon") {
        return std::unique_ptr<BattleCard>(new Dragon());
    }
    if (name == "Goblin") {
        return std::unique_ptr<BattleCard>(new Goblin());
    }
    if (name == "Vampire") {
        return std::unique_ptr<BattleCard>(new Vampire());
    }
    try {
        if (name == "Gang") {
            return std::unique_ptr<BattleCard>(new Gang(cardDeckFile, lineNumber));
        }
    }
    catch (BadGangFormat &e) {
        throw DeckFileFormatError(lineNumber);
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

    return std::unique_ptr<Card>(std::move(Factories::createBattleCardFromStream(cardDeckFile, name, lineNumber)));

}

std::unique_ptr<Player> Factories::createPlayer(std::string& name, std::string& job) {
    if(!isValidName(name)){
        throw InvalidName();
    }
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

