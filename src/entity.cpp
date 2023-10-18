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

//Delegations

void Entity::getAddItem(const std::string& name, const std::string& description, int attack, int defense, int flag)
{
    inventory.addItem(name, description, attack, defense, flag);
}

const std::string& Entity::getItemName(const int& dataIndex) const
{
    return inventory.getName(dataIndex);
}

void Entity::getDisplayInventory()
{
    inventory.displayItems();
}

int Entity::inventorySize()
{
    return inventory.inventorySize();
}

void Entity::getDisplayItem(const int& dataIndex)
{
    inventory.displayInfo(dataIndex);
}

void Entity::useItem(const int& dataIndex)
{
    std::cout << "Used 1 " << getItemName(dataIndex) << "\n";
    health = health + inventory.getAttack(dataIndex);
    inventory.removeItem(dataIndex);
    std::cout << health << "\n";
}