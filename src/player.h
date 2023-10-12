#pragma once

#include <iostream>
#include "item.h"

class Player
{
    public:
        Player();

        const std::string& getName() const;
        const int& getHP() const;
        const int& getAttack() const;
        const int& getDefense() const;
        void setName(const std::string& name);
        void displayInfo();

        //Delegations
        void getDisplayInventory();
        void getDisplayItem();
        void getAddItem(const Item& newItem);
        const std::string& getItemName(const int& dataIndex) const;

    private:
        std::string name;
        int health = 100;
        int attackStat = 1;
        int defenseStat = 1;
        InventoryItem inventory;
};
