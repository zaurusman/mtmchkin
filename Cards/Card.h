//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_CARD_H
#define MTMCHKIN_CARD_H


#include <string>
#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include "../Players/Wizard.h"
#include "../Players/Fighter.h"
#include "utilities.h"

//TODO: explain about the card class, check if assignment/copy are needed.
class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */

    Card(std::string cardName);

     /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
     virtual void applyEncounter(Player& player) const = 0;

    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo() const = 0 ;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */

    ~Card() = default;
    Card(const Card&) = delete;
    Card& operator=(const Card& other) = delete;

    void getInfoStream(std::ostream& outStream) const;
    virtual void getCardDetails(std::ostream& outStream) const = 0; //TODO: IMPLEMENT FOR ALL CARDS

private:
    std::string m_cardName;
};

std::ostream& operator<<(std::ostream& outStream, const Card &card);

#endif //MTMCHKIN_CARD_H
