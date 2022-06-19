//
// Created by Yotam on 02/05/2022.
//

#include "Player.h"
#include "../utilities.h"

static bool isValidName(std::string name);

Player::Player(std::string name) :
    m_name(""),
    m_level(Player::DEFAULT_START_LEVEL),
    m_force(Player::DEFAULT_FORCE),
    m_maxHP(Player::DEFAULT_MAX_HP),
    m_HP(Player::DEFAULT_MAX_HP),
    m_coins(Player::DEFAULT_COINS)
{
    if(!isValidName(name))
    {
        throw InvalidName();
    }
    m_name = name;
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
    if (increment >=0)
    {
        m_force += increment;
    }
}
void Player::unBuff(int decrease)
{
    if (decrease >=0)
    {
        m_force -= decrease;
        if(m_force <= 0){
            m_force = 0;
        }
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

void Player::getInfoStream(std::ostream& outStream) const{
    printPlayerDetails(outStream, m_name, this->getJob(), m_level, m_force, m_HP, m_coins);

}

std::ostream& operator<<(std::ostream& outStream, const Player& player){
    player.getInfoStream(outStream);
    return outStream;
}

std::string Player::getName() const
{
    return m_name;
}

int Player::getCoins() const
{
    return m_coins;
}

int Player::getHP() const
{
    return m_HP;
}

static bool isValidName(std::string name)
{
    if(name.length()>15)
    {
        return false;
    }
    std::string criteria("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY");
    return (std::string::npos == name.find_first_not_of(criteria));
}

bool Player::isMaxLevel() const{
    return this->getLevel() == Player::MAX_LEVEL;
}

void Player::levelDown(){
    if(m_level>=1){
        m_level--;
    }
}
