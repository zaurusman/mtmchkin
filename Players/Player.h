//
// Created by Yotam on 02/05/2022.
//
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
//#include "utilities.h"



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
     * @param name - The name of the player, must be composed of less than 16 english characters.
     * @return
     *      A new instance of Player.
    */
    explicit Player(std::string name);

    /*
     * levels up the player (up to a max of level 10).
     * @return
     *      void
    */
    void levelUp();

    /*
     * levels down the player (down to a min of level 0).
     * @return
     *      void
    */
    void levelDown();

    /*
     * checks if the player's level is the max level
     * @return
     *      true iff the level is the max level
    */
    bool isMaxLevel() const;

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

    /*
     * increase the HP of the player by a given amount (up to maxHP).
     * @param increment - the amount to add to HP.
     * @return
     *      void
    */
    virtual void heal(int increment);

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


    /*
     * updates a given ostream with player related info.
     * @return
     *      the updated ostream.
    */
    void getInfoStream(std::ostream& outStream) const;


    /* gives the current class of the player,
    * @return
    *      player's class.
    */
    virtual std::string getJob() const = 0;


    /* getter for the player's name.
    * @return
    *      player's name.
    */
    std::string getName() const;

    /* getter for the player's coins.
    * @return
    *      player's coins.
    */
    int getCoins() const;

    /* getter for the player's HP.
    * @return
    *      player's HP.
    */
    int getHP() const;

    /* decreases the player's strength by argument.
     * @param decrease - amount to decrease, must be a natural number;
    * @return
    *      player's name.
    */
    void unBuff(int decrease);

    /*
     * using default d'tor, cpy c'tor and assignment operator.
     */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;


private:
    /* Class related constants:
     *  DEFAULT_MAX_HP - default value for max hp.
     *  DEFAULT_FORCE - default value for force.
     *  MAX_LEVEL - the maximum level that can be reached.
     *  DEFAULT_COINS - default start coins
     *  DEFAULT_START_LEVEL - default start level
     *  MAX_LEVEL - max level that can be reached.
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

/*
 * overloading assignment operator to print player related info.
 * returns updated stream to allow chaining.
 */
std::ostream& operator<<(std::ostream& outStream, const Player& player);





#endif //EX2_PLAYER_H
