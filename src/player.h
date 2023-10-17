#pragma once

#include <iostream>
#include "item.h"
#include "entity.h"

class Player : public Entity
{
    public:
        Player();

        //Delegations
        void getDisplayInventory();
        void getDisplayItem();
        void getAddItem(const Item& newItem);
        const std::string& getItemName(const int& dataIndex) const;
        const int& inventorySize() const;
        void getDisplayItem(const int& dataIndex);
};
