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

void Player::getAddItem(const Item& item)
{
    inventory.addItem(item);
}

const std::string& Player::getItemName(const int& dataIndex) const
{
    return inventory.getName(dataIndex);
}

void Player::getDisplayInventory()
{
    inventory.displayItems();
}

const int& Player::inventorySize() const
{
    return inventory.inventorySize();
}

void Player::getDisplayItem(const int& dataIndex)
{
    inventory.displayInfo(dataIndex);
}

