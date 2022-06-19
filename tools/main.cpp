//
// Created by Yotam on 19/06/2022.
//

#include "Exception.h"
#include "Mtmchkin.h"
#include <string>

const std::string deckFile = "deck.txt";



int macin()
{
    try
    {
        Mtmchkin game(deckFile);
        while(!game.isGameOver())
        {
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}