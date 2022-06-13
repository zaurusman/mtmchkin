#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_


#include <string>
#include <fstream>
#include <queue>
#include <memory>
#include "Cards/Card.h"
#include <Cards/Dragon.h>
#include <Cards/Barfight.h>
#include <Cards/Fairy.h>
#include <Cards/Goblin.h>
#include <Cards/Merchant.h>
#include <Cards/Pitfall.h>
#include <Cards/Treasure.h>
#include <Cards/Vampire.h>

#include "Players/Player.h"


class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;



    static std::unique_ptr<Card> createCardByName(std::string name);
    static std::unique_ptr<Player> createPlayerByJob(std::string nameJob);
private:
    static const int BUFFER = 256;
    static const int MAX_TEAM_SIZE = 6;
    static const int MIN_TEAM_SIZE = 2;

    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>> m_players;

};



#endif /* MTMCHKIN_H_ */
