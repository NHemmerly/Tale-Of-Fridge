#include "player.h"

Player::Player(const std::string& name)
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