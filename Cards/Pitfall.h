//
// Created by Yotam on 08/06/2022.
//

#ifndef MTMCHKIN_PITFALL_H
#define MTMCHKIN_PITFALL_H


#include "Card.h"

class Pitfall : public Card{
public:

    Pitfall();
    ~Pitfall() = default;
    void applyEncounter(Player& player) const override;
    void getCardDetails(std::ostream& outStream) const override;
private:
    static const int DAMAGE =10;
};


#endif //MTMCHKIN_PITFALL_H
