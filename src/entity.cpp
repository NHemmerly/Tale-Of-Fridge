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

void Entity::applyStats(const int& dataIndex)
{
    health = health - inventory.getAttack(dataIndex);
    defenseStat = defenseStat + inventory.getDefense(dataIndex);
}

void Entity::useItem(const int& dataIndex)
{
    int currentHealth = health;
    int currentDefense = defenseStat;
    std::cout << "Used 1 " << getItemName(dataIndex) << "\n";
    applyStats(dataIndex);
    if (currentHealth > health)
    {
        std::cout << "You took " << abs(inventory.getAttack(dataIndex)) << " damage!" << "\n";
    } else if (currentHealth < health)
    {
        std::cout << "You gained " << abs(inventory.getAttack(dataIndex)) << " health!" << "\n";
    }
    if (currentDefense > defenseStat)
    {
        std::cout << "You lost " << abs(inventory.getDefense(dataIndex)) << " defense!" << "\n";
    } else if (currentDefense < defenseStat)
    {
        std::cout << "You gained " << abs(inventory.getDefense(dataIndex)) << " defense!" << "\n";
    }
    inventory.removeItem(dataIndex);
    std::cout << "Current health: " << health << "\n";
}
