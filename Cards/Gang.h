//
// Created by Yotam on 19/06/2022.
//

#ifndef MTMCHKIN_GANG_H
#define MTMCHKIN_GANG_H
#include "Card.h"
#include "../Factories.h"
#include <fstream>
#include <memory>
#include <vector>


class Gang : public BattleCard {
public:
    Gang(std::istream &cardList,int lineNumber);

    void applyEncounter(Player &player) const override;

    int getSize() const;

private:
    const int GANG_STAT = 0;
    std::vector<std::unique_ptr<BattleCard>> m_monsters;

};


#endif //MTMCHKIN_GANG_H
