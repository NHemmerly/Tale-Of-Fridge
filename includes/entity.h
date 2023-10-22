#pragma once

#include <string>
#include <iostream>
#include <memory>

#include "item.h"


class Entity
{
public:
    Entity();
    Entity(const std::string& name, const int& health, const int& attackStat, const int& defenseStat);
    const std::string& getName() const;
    const int& getHP() const;
    const int& getAttack() const;
    const int& getDefense() const;
    void setName(const std::string& name);
    void displayInfo();
    void useItem(const int& dataIndex);
    void takeDamage(const int& damage);
    void changeDefense(const int& defense);
    void displayDamage(const int& damage);
    void displayDefense(const int& defense);
    InventoryItem inventory;
protected:
    void applyStats(const int& dataIndex);
    std::string name;
    int health = 100;
    int attackStat = 1;
    int defenseStat = 1;
    

};
