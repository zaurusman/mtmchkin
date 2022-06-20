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
    Gang();

    void applyEncounter(Player &player) const override;

    void addMonster(BattleCard& card);

    int getSize() const;

private:
    static const int GANG_STAT = 0;
    std::vector<std::unique_ptr<BattleCard>> m_monsters;

};


#endif //MTMCHKIN_GANG_H
