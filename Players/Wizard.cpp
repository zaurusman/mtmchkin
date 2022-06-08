//
// Created by Yotam on 07/06/2022.
//

#include "Wizard.h"

Wizard::Wizard(std::string name): Player(name) {}


void Wizard::heal(int increment)
{
    Player::heal(2*increment);
}
std::string Wizard::getJob() const {
    return "Wizard";
}