#include "player.h"

Player::Player()
{
    this->name = name;
    this->health = health;
    this->defenseStat = defenseStat;
    this->attackStat = attackStat;
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

