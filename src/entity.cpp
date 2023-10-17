#include "entity.h"

const std::string& Entity::getName() const 
{
    return name;
}

void Entity::setName(const std::string& newName)
{
    name = newName;
}

const int& Entity::getHP() const 
{
    return health;
}

const int& Entity::getAttack() const 
{
    return attackStat;
}

const int& Entity::getDefense() const 
{
    return defenseStat;
}

void Entity::displayInfo()
{
    std::cout << "==================================\n"
    << name
    << "\n=================================="
    << "\nHealth: " << health
    << "\nAttack: " << attackStat
    << "\nDefense: " << defenseStat
    << "\n0. exit\n"
    << "=================================="
    << "\n";
}