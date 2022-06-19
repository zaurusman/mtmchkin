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
#include "Factories.h"

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
    explicit Mtmchkin(const std::string& fileName);
    
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


private:

    /*
    *  Gets input for team size from user,
    *  check if it's valid - between 2 and 6.
    *  if not - asks for it again.
    *
    *  @return
    *         int of a valid team size.
    */
    static int initTeamSize();

    void createPlayerQueue(int teamSize);


    static const char NAME_DELIMITER = ' ';
    static const char JOB_DELIMITER = '\n';
    static const int MAX_TEAM_SIZE = 6;
    static const int MIN_TEAM_SIZE = 2;
    static const int MIN_DECK_SIZE = 5;

    int m_roundCount;
    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>> m_activePlayers;
    std::deque<std::unique_ptr<const Player>> m_winners;
    std::deque<std::unique_ptr<const Player>> m_losers;

};



#endif /* MTMCHKIN_H_ */
