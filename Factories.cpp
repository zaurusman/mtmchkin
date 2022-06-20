//
// Created by Elad on 19/06/2022.
//

#include "Factories.h"
std::unique_ptr<BattleCard> Factories::createSingleBattleCard(std::string& name, int& lineNumber) {
    if (name == "Dragon") {
        return std::unique_ptr<BattleCard>(new Dragon());
    }
    if (name == "Goblin") {
        return std::unique_ptr<BattleCard>(new Goblin());
    }
    if (name == "Vampire") {
        return std::unique_ptr<BattleCard>(new Vampire());
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
    if (name == "Gang") {
        return Factories::createGang(cardDeckFile, lineNumber);
    }
    return std::move(Factories::createSingleBattleCard(name, lineNumber));
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

std::unique_ptr<Card> Factories::createGang(std::istream &cardDeckFile, int& lineNumber){
    std::unique_ptr<Gang> newGang(new Gang());
    std::string cardName;
    while(getline(cardDeckFile, cardName) && cardName!="EndGang")
    {
        lineNumber++;
        std::unique_ptr<BattleCard> cardPtr(std::move(Factories::createSingleBattleCard(cardName, lineNumber)));
        BattleCard& card = *cardPtr;
        newGang->addMonster(card);
    }
    if (cardName!="EndGang"){
        throw BadGangFormat(lineNumber);
    }
    return std::unique_ptr<BattleCard>(std::move(newGang));
}



