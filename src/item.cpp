#include "item.h"

InventoryItem::InventoryItem()
{
    this->inventory = inventory;
}

 //Getters
const std::string& InventoryItem::getName(const int& dataIndex) const
{
    return inventory[dataIndex].getName();
}
const std::string& InventoryItem::getDescription(const int& dataIndex) const
{
    return inventory[dataIndex].getDescription();

}
const int InventoryItem::getAttack(const int& dataIndex) const
{
    return inventory[dataIndex].getAttack();
}
const int InventoryItem::getDefense(const int& dataIndex) const
{
    return inventory[dataIndex].getDefense();
}

void InventoryItem::displayInfo(const int& dataIndex)
{
    inventory[dataIndex].displayInfo();
}


const std::string& Item::getName() const
{
    return name;
}

const std::string& Item::getDescription() const
{
    return description;
}

const int Item::getAttack() const
{
    return attack;
}
    
const int Item::getDefense() const
{
    return defense;
}

void Item::displayInfo()
{
    std::cout << "\n" << name << "\n" <<
    "===================================================\n" << 
    "Description: " << description << "\n" <<
    "Attack: " << attack << "\n" << 
    "Defense: " << defense << std::endl;
}

//Adders

void InventoryItem::addItem(const Item& newItem)
{
    inventory.push_back(newItem);
}


//Setters
void Item::setName(const std::string& newName)
{
    name = newName;
}


void InventoryItem::setName(int index, const std::string& newName)
{
    if (index >= 0 && index < inventory.size())
    {
        inventory[index].setName(newName);
    }
}
void InventoryItem::setDescription(int index, const std::string& newDescription)
{

}
void InventoryItem::setAttack(int index, const int& newAttack)
{

}
void InventoryItem::setDefense(int index, const int& newDefense)
{
    
}
