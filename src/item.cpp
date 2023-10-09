#include "item.h"


 //Getters
const std::string& InventoryItem::getName() const
{
    return itemInitializationData[dataIndex]->name;
}
const std::string& InventoryItem::getDescription() const
{
    return itemInitializationData[dataIndex]->itemDescription;

}
const int InventoryItem::getAttack() const
{
    return itemInitializationData[dataIndex]->attack;
}
const int InventoryItem::getDefense() const
{
    return itemInitializationData[dataIndex]->defense;
}

//Setters
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
