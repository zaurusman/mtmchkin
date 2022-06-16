//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_ROGUE_H
#define MTMCHKIN_ROGUE_H

#include "Player.h"

/* Rogue:
     * Rogue is a type of player:
     * special ability: gets 2x coins during the whole game.
    */

class Rogue : public Player {

public:
    /*
     * C'tor for Rogue class:
     *
     * @param name - the name of the player
     *return
     *      a new instance of Rogue
     */
    Rogue(std::string name);


    /*
     * adds to the Rogue's coins, calculated as mentioned above.
     *
     *return
     *      void
     */
    void addCoins(int increment) override;

    /*
     * getter for the Rogue's job (Rogue)
     * returns
     *      the string "Rogue"
     */
    std::string getJob() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Rogue()=default;
    Rogue(const Rogue &other) = default;
    Rogue& operator=(const Rogue &other) = default;
};


#endif //MTMCHKIN_ROGUE_H
