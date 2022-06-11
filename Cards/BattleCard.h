//
// Created by Yotam on 07/06/2022.
//

#ifndef MTMCHKIN_BATTLECARD_H
#define MTMCHKIN_BATTLECARD_H


#include "Card.h"

class BattleCard : public Card {

public:
    BattleCard(int force, int loot, int loss, std::string name);
    ~BattleCard()=default;
    void getInfoStream(std::ostream &outStream) const override;
    void applyEncounter(Player &player) const override;
protected:
    static const int INFINITE_DAMAGE = -1;
private:
    int m_force;
    int m_loot;
    int m_loss;


};


#endif //MTMCHKIN_BATTLECARD_H
