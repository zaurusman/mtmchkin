//
// Created by Yotam on 19/06/2022.
//

#include "Exception.h"
#include "Mtmchkin.h"
#include "string"


int mcain()
{
    const std::string deckFile = "deck.txt";
    const int MAX_ROUNDS = 100;
    int count = 0 ;
    try
    {
        Mtmchkin game(deckFile);
        while(!game.isGameOver() && count < MAX_ROUNDS)
        {
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(const std::exception& gameException)
    {
        std::cout << gameException.what() << std::endl;
    }
    return 0;
}