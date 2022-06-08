//
// Created by Yotam on 02/05/2022.
//
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
#include "utilities.h"



/* Player:
     * Each player has:
     * name - only english letters.
     * level - a natural number between 1-10.
     * force - a natural number.
     * maxHP - a natural number.
     * Health Points - the current HP of the player. a natural number between 0-MaxHP
     * coins - the amount of coins the player has. a natural number.
    */

class Player {
public:


    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param force - The force of the player (default = DEFAULT_FORCE).
     * @param maxHP - The max health points (default = DEFAULT_MAX_HP).
     * @return
     *      A new instance of Player.
    */
    explicit Player(std::string name);

    /*
     * prints the stats of the player
     * @return
     *      void
    */
    void printInfo()const;

    /*
     * levels up the player (up to a max of level 10).
     * @return
     *      void
    */
    void levelUp();

    /*
     * gives the current level of the player.
     * @return
     *      player's level
    */
    int getLevel()const;

    /*
     * increase the force of the player by a given amount.
     * @param increment - the amount to add to force.
     * @return
     *      void
    */
    void buff(int increment);

    virtual /*
     * increase the HP of the player by a given amount (up to maxHP).
     * @param increment - the amount to add to HP.
     * @return
     *      void
    */
    void heal(int increment);

    /*
     * decrease the HP of the player by a given amount.
     * @param decrement - the amount needed to be decreased from HP.
     * @return
     *      void
    */
    void damage(int decrease);

    /*
     * checks if the players HP is 0.
     * @return
     *      true - HP is 0.
     *      false - HP is not 0.
    */
    bool isKnockedOut()const;

    /*
     * increase the coins of the player by a given amount.
     * @param increment - the amount of coins to add.
     * @return
     *      void
    */
    virtual void addCoins(int increment);

    /*
     * decrease the coins amount of the player by a given amount.
     * if the payment is larger than the amount of coins. the payment
     * will not be processed.
     * @param decrement - the amount needed to be decreased from coins.
     * @return
     *      true - the payment was done successfully.
     *      false - the payment has failed.
    */
    bool pay(int decrease);

    /*
     * gives the current attack strength of the player,
     * which is determined by: level + force.
     * @return
     *      player's attack strength.
    */
    virtual int getAttackStrength()const;


    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

    virtual std::string getJob() const = 0;
private:
    /* Class related constants:
     *  DEFAULT_MAX_HP - default value for max hp.
     *  DEFAULT_FORCE - default value for force.
     *  MAX_LEVEL - the maximum level that can be reached.
     * */

    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;
    static const int DEFAULT_COINS = 10;
    static const int DEFAULT_START_LEVEL = 1;
    static const int MAX_LEVEL = 10;

    std::string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;


};

std::ostream& operator<<(std::ostream& outStream, const );





#endif //EX2_PLAYER_H
