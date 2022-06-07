//
// Created by Yotam on 07/06/2022.
//

#include "Wizard.h"

Wizard::Wizard(std::string name, int maxHP, int force): Player(name,maxHP,force)
{}


void Wizard::heal(int increment)
{
    Player::heal(2*increment);
}

PlayerClass Wizard::getClass() const
{
    return PlayerClass::Wizard;
}