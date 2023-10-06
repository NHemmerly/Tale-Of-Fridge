#include "player.h"

Player::Player()
{
    this->name = name;
    this->health = health;
    this->defenseStat = defenseStat;
    this->attackStat = attackStat;
}

const std::string& Player::getName() const 
{
    return name;
}

void Player::setName(const std::string& newName)
{
    name = newName;
}

const int& Player::getHP() const 
{
    return health;
}

const int& Player::getAttack() const 
{
    return attackStat;
}

const int& Player::getDefense() const 
{
    return defenseStat;
}

void Player::displayInfo()
{
    std::cout << "Name: " << name
    << "\nHealth: " << health
    << "\nAttack: " << attackStat
    << "\nDefense: " << defenseStat
    << std::endl;
}
