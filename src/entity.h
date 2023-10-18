#pragma once

#include <string>
#include <iostream>

#include "usables.h"

class Entity
{
public:
    const std::string& getName() const;
    const int& getHP() const;
    const int& getAttack() const;
    const int& getDefense() const;
    void setName(const std::string& name);
    void displayInfo();
    void useItem(const int& dataIndex);

    void getDisplayInventory();
    void getDisplayItem();
    void getAddItem(const std::string& name, const std::string& description, int attack, int defense);
    const std::string& getItemName(const int& dataIndex) const;
    const int& inventorySize() const;
    void getDisplayItem(const int& dataIndex);

protected:
    std::string name;
    int health = 100;
    int attackStat = 1;
    int defenseStat = 1;
    InventoryItem inventory;
};