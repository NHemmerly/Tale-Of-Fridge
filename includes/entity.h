#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "item.h"


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
    void takeDamage(const int& damage);
    void changeDefense(const int& defense);

    void getDisplayInventory();
    void getDisplayItem();
    void getAddItem(const std::string& name, const std::string& description, int attack, int defense, int flag = 0);
    const std::string& getItemName(const int& dataIndex) const;
    int inventorySize();
    void getDisplayItem(const int& dataIndex);
    void displayDamage(const int& damage);
    void displayDefense(const int& defense);

protected:
    void applyStats(const int& dataIndex);
    std::string name;
    int health = 100;
    int attackStat = 1;
    int defenseStat = 1;
    InventoryItem inventory;
    

};
