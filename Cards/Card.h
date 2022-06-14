//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_CARD_H
#define MTMCHKIN_CARD_H


#include <string>
#include "../Players/Player.h"
#include "../Players/Rogue.h"
#include "../Players/Fighter.h"
#include "../Players/Wizard.h"
#include "utilities.h"

//TODO: explain about the card class
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

    explicit Card(std::string cardName);

     /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      voi
    */
     virtual void applyEncounter(Player& player) const = 0;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    std::string getName() const;
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;

    virtual void getInfoStream(std::ostream &outStream) const;

private:
    std::string m_cardName;

};

std::ostream& operator<<(std::ostream& outStream, const Card &card);

#endif //MTMCHKIN_CARD_H
