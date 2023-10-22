#include "player.h"

Player::Player() : Entity()
{
            name = "none";
            health = 100;
            attackStat = 0;
            defenseStat = 0;
};

Player::Player(const std::string& defaultName, const int& defHealth, const int& defAttackStat, const int& defDefenseStat)
            : Entity(defaultName, defHealth, defAttackStat, defDefenseStat) 
{
    name = defaultName;
    health = defHealth;
    attackStat = defAttackStat;
    defenseStat = defDefenseStat;
};



