#include "Exception.h"
#include "Mtmchkin.h"

const string deckFile = "deck.txt";



int main(){

    try
    {
        Mtmchkin game(deckFile);
        while(!game.isGameEnded())
        {
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
