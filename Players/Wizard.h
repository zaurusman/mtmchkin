//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_WIZARD_H
#define MTMCHKIN_WIZARD_H

#include "Player.h"

/* Wizard:
     * Wizard is a type of player:
     * special ability: the effect of a healing card is doubled.
    */

class Wizard : public Player {

public:
    /*
     * C'tor for Wizard class:
     *
     * @param name - the name of the player
     *return
     *      a new instance of Wizard
     */
    explicit Wizard(std::string name);

    /*
     * adds to the Wizard's HP, calculated as mentioned above.
     *
     *return
     *      void
     */
    void heal(int increment) override;

    /*
     * getter for the Wizard's job (Wizard)
     * returns
     *      the string "Wizard"
     */
    std::string getJob() const override;

    /*
    * Here we are explicitly telling the compiler to use the default methods
    */
    ~Wizard() override =default;
    Wizard(const Wizard &other) = default;
    Wizard& operator=(const Wizard &other) = default;
};


#endif //MTMCHKIN_WIZARD_H
