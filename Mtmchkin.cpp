//
// Created by Yotam on 09/06/2022.
//


#include "Mtmchkin.h"

//TODO: MAP
Mtmchkin::Mtmchkin(std::string fileName):
m_activePlayers(std::deque<std::unique_ptr<Player>>()),
m_winners(std::deque<std::unique_ptr<const Player>>()),
m_losers(std::deque<std::unique_ptr<const Player>>())
{
    std::ifstream cardDeckFile(fileName);
    if(!cardDeckFile)
    {
        throw DeckFileNotFound();
    }
    std::string line;
    int lineNumber = 0;
    while (getline(cardDeckFile, line))
    {
        lineNumber++;
        m_deck.push_front(createCardByName(line,lineNumber));
    }
    if(lineNumber < MIN_DECK_SIZE){
        throw DeckFileInvalidSize();
    }
    printEnterTeamSizeMessage();
    bool isValidSize = false;
    int teamSize;
    while(!isValidSize)
    {
        //TODO: check input
        std::cin>>teamSize;
        std::cout<<std::endl;
        if(teamSize<=MAX_TEAM_SIZE&teamSize>=MIN_TEAM_SIZE)
        {
            isValidSize = true;
        }
        else
        {
            printInvalidTeamSize();
        }
    }
    std::string nameJob;
    for (int i = 0; i < teamSize; i++)
    {
        printInsertPlayerMessage();
        //TODO::check inputs
        std::cin >> nameJob;
        try {
            m_activePlayers.push_front(createPlayerByJob(nameJob));
        }
        catch(const InvalidName)
        {
            printInvalidName();
            i--;
        }
        catch(const InvalidClass)
        {
            printInvalidClass();
            i--;
        }
    }
    m_roundCount = 1;
}
std::unique_ptr<Card> Mtmchkin::createCardByName(std::string name, int line)
{

    if(name == "Barfight")
    {
        return std::unique_ptr<Card>(new Barfight());
    }
    if(name == "Dragon")
    {
        return std::unique_ptr<Card>(new Dragon());
    }
    if(name == "Fairy")
    {
        return std::unique_ptr<Card>(new Fairy());
    }
    if(name == "Goblin")
    {
        return std::unique_ptr<Card>(new Goblin());
    }
    if(name == "Merchant")
    {
        return std::unique_ptr<Card>(new Merchant());
    }
    if(name == "Pitfall")
    {
        return std::unique_ptr<Card>(new Pitfall());
    }
    if(name == "Treasure")
    {
        return std::unique_ptr<Card>(new Treasure());
    }
    if(name == "Vampire")
    {
        return std::unique_ptr<Card>(new Vampire());
    }
    throw DeckFileFormatError(line);
}

std::unique_ptr<Player> createPlayerByJob(std::string nameJob)
{
    //TODO:exceptions 
    std::string name = nameJob.substr(0, nameJob.find(" "));
    std::string job = nameJob.substr(name.length()+1);
    if (job == "Fighter") {
        return std::unique_ptr<Player>(new Fighter(name));
    }
    if (job == "Rogue") {
        return std::unique_ptr<Player>(new Rogue(name));
    }
    if (job == "Wizard") {
        return std::unique_ptr<Player>(new Wizard(name));
    } else
    {
        throw InvalidClass();
    }
}


void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundCount);
    for (int i = 0; i < m_activePlayers.size(); ++i)
    {
        std::unique_ptr<Player> currentPlayer = move(m_activePlayers.front());
        m_activePlayers.pop_front();
        std::unique_ptr<Card> currentCard = move(m_deck.front());
        m_deck.pop_front();
        printTurnStartMessage(currentPlayer->getName());
        currentCard->applyEncounter(*currentPlayer);
        if(currentPlayer->isKnockedOut())
        {
            m_losers.push_front(move(currentPlayer));
        }
        else if(currentPlayer->getLevel()==WINNING_LEVEL)
        {
            m_winners.push_front(move(currentPlayer));
        } else
        {
            m_activePlayers.push_back(move(currentPlayer));
        }
        m_deck.push_back(move(currentCard));
    }
}
int Mtmchkin::getNumberOfRounds() const
{
    return (m_roundCount-1);
}
