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

    /*
   * updates a given ostream with card related info.
   * @return
   *      the updated ostream.
  */
    Gang(std::istream &cardList,int& lineNumber);


    /*
     * applies the encounter for the Gang:
     * if the player has enough force he levels up and gets the loot, else he losses health from all
     * subsequent monsters.
     * @param player - the player who activated the card.
     * returns
     *          void
     */
    void applyEncounter(Player &player) const override;

    /*
    * updates a given ostream with card related info.
    * @return
    *      the updated ostream.
   */
    void getInfoStream(std::ostream &outStream) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Gang() override = default;
    Gang(const Gang& other) = default;
    Gang& operator=(const Gang& other) = default;
private:
    const int GANG_STAT = 0;
    std::vector<std::shared_ptr<BattleCard>> m_monsters;

};


#endif //MTMCHKIN_GANG_H
