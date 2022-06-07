//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_PITFALL_H
#define MTMCHKIN_PITFALL_H


#include "Card.h"

class Pitfall : public virtual Card{
public:

    Pitfall();
    void applyEncounter(Player& player) const override;
private:
    static const int DAMAGE =10;
};


#endif //MTMCHKIN_PITFALL_H
