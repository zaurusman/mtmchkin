//
// Created by Yotam on 02/05/2022.
//

#include "Player.h"


Player::Player(std::string name, int maxHP, int force) :
    m_name(name),
    m_level(1),
    m_force(force),
    m_maxHP(maxHP),
    m_HP(maxHP),
    m_coins(10)//TODO: maybe make a new constructor for coin input
{
    if (force <= 0)
    {
        m_force = DEFAULT_FORCE;
    }
    if (maxHP <= 0){
        m_maxHP = Player::DEFAULT_MAX_HP;
        m_HP = Player::DEFAULT_MAX_HP;
    }
}
void Player::printInfo() const
{
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp()
{
    if(m_level + 1 <= MAX_LEVEL)
    {
        ++m_level;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(int increment)
{
    if (increment >=0 )
    {
        m_force += increment;
    }
}

void Player::heal(int increment)
{
    if (increment >=0 )
    {
        m_HP += increment;
        if (m_HP > m_maxHP)
        {
            m_HP = m_maxHP;
        }
    }
}

void Player::damage(int decrease)
{
    if(decrease >= 0)
    {
        m_HP -= decrease;
        if (m_HP < 0)
        {
            m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    if(m_HP == 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int increment)
{
    if (increment >=0 )
    {
        m_coins += increment;
    }
}

bool Player::pay(int price)
{
    if(m_coins >= price)
    {
        if(price >= 0) {
            m_coins -= price;
        }
        return true;
    }
    return false;
}

int Player::getAttackStrength() const
{
    return (m_level + m_force);
}


