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
     * @param cardName - The type of the card.
     * @return
     *      A new instance of Card.
    */

    explicit Card(std::string cardName);

     /*
     * applies the card related encounter:
     *
     * @param player - the player who activated the card.
     * @return
     *      void
    */
     virtual void applyEncounter(Player& player) const = 0;


     /*
      * getter for the card's name
      * returns the card's name
      */
    std::string getName() const;

    /*
     * updates a given ostream with card related info.
     * @return
     *      the updated ostream.
    */
    virtual void getInfoStream(std::ostream &outStream) const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;
private:
    std::string m_cardName;

};

/*
 * overloading assignment operator to print card related info.
 * returns updated stream to allow chaining.
 */
std::ostream& operator<<(std::ostream& outStream, const Card &card);

#endif //MTMCHKIN_CARD_H
