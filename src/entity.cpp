#include "entity.h"

Entity::Entity()
{
    name = "none";
    health = 100;
    attackStat = 0;
    defenseStat = 0;
}

Entity::Entity(const std::string& name, const int& health, const int& attackStat, const int& defenseStat)
    : name(name), health(health), attackStat(attackStat), defenseStat(defenseStat) {
        maxHealth = health;
    };


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

const int& Entity::getMaxHp() const
{
    return maxHealth;
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

//Delegations

void Entity::displayDamage(const int& damage)
{
    if (damage > 0)
    {
        std::cout << "You took " << abs(damage) << " damage!" << "\n";
    } else if (damage < 0)
    {
        std::cout << "You gained " << abs(damage) << " health!" << "\n";
    } 
}

void Entity::displayDefense(const int& defense)
{
    if (defense < 0)
    {
        std::cout << "You lost " << abs(defense) << " defense!" << "\n";
    } else if (defense > 0)
    {
        std::cout << "You gained " << abs(defense) << " defense!" << "\n";
    }
}

void Entity::takeDamage(const int& damage)
{
    health -= damage;
    displayDamage(damage);
}

void Entity::changeDefense(const int& defense)
{
    defenseStat += defense;
    displayDefense(defense);
}

void Entity::applyStats(const int& dataIndex)
{
    if (inventory.usable(dataIndex))
    {
        std::cout << "Used 1 " << inventory.getName(dataIndex) << "\n";
        takeDamage(inventory.getAttack(dataIndex));
        changeDefense(inventory.getDefense(dataIndex));
        std::cout << "Current Health: " << health << "\n";
        inventory.removeItem(dataIndex);
    } else 
    {
        std::cout << "This item is not usable" << "\n";
    }
}

void Entity::useItem(const int& dataIndex)
{
    applyStats(dataIndex);
}
