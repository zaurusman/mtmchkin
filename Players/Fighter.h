//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_FIGHTER_H
#define MTMCHKIN_FIGHTER_H

#include "Player.h"

/* Fighter:
     * Fighter is a type of player:
     * special ability: attack calculated by: force*2+level
    */

class Fighter :public Player {

public:
    /*
     * C'tor for Fighter class:
     *
     * @param name - the name of the player
     *return
     *      a new instance of Fighter
     */
    explicit Fighter(std::string name);

    /*
     * getter for the Fighter attack strength, calculated as mentioned above.
     *
     *return
     *      the fighter's attack strength
     */
    int getAttackStrength() const override;

    /*
     * getter for the Fighter's job (fighter)
     * returns
     *      the string "Fighter"
     */
    std::string getJob() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fighter() override=default;
    Fighter(const Fighter &other) = default;
    Fighter& operator=(const Fighter &other) = default;
};


#endif //MTMCHKIN_FIGHTER_H
