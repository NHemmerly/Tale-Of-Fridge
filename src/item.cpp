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

const std::string& Item::getName() const
{
    return name;
}

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
