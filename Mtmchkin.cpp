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
        m_deck.push(createCardByName(line));
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
        //TODO::check input
        std::cin >> nameJob;
        m_players.push(createPlayerByJob(nameJob));
    }

}
std::shared_ptr<Card> Mtmchkin::createCardByName(std::string name) const
{

    if(name == "Barfight")
    {
        return std::shared_ptr<Card>(new Barfight());
    }
    if(name == "Dragon")
    {
        return std::shared_ptr<Card>(new Dragon());
    }
    if(name == "Fairy")
    {
        return std::shared_ptr<Card>(new Fairy());
    }
    if(name == "Goblin")
    {
        return std::shared_ptr<Card>(new Goblin());
    }
    if(name == "Merchant")
    {
        return std::shared_ptr<Card>(new Merchant());
    }
    if(name == "Pitfall")
    {
        return std::shared_ptr<Card>(new Pitfall());
    }
    if(name == "Treasure")
    {
        return std::shared_ptr<Card>(new Treasure());
    }
    if(name == "Vampire")
    {
        return std::shared_ptr<Card>(new Vampire());
    }
}

std::shared_ptr<Player> createPlayerByJob(std::string nameJob)
{
    //TODO:exceptions 
    std::string name = nameJob.substr(0, nameJob.find(" "));
    std::string job = nameJob.substr(name.length()+1);
    if (job == "Fighter")
    {
        return std::shared_ptr<Player>(new Fighter(name));
    }
    if (job == "Rogue")
    {
        return std::shared_ptr<Player>(new Rogue(name));
    }
    if (job == "Wizard")
    {
        return std::shared_ptr<Player>(new Wizard(name));
    } else
    {

    }
}