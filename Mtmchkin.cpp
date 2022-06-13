//
// Created by Yotam on 09/06/2022.
//


#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(std::string fileName)
{
    std::ifstream cardDeckFile(fileName);
    if(!cardDeckFile)
    {
        //TODO: add exception
    }
    char line[BUFFER];
    while (cardDeckFile.getline(line, sizeof(line)))
    {
        //TODO:check input
        m_deck.push_front(createCardByName(line));
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
            m_players.push_front(createPlayerByJob(nameJob));
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

}
std::unique_ptr<Card> Mtmchkin::createCardByName(std::string name)
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