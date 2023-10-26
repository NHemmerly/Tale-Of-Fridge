#include "item.h"
#include "weapons.h"
InventoryItem::InventoryItem()
{}


 //Getters
const std::string& InventoryItem::getName(const int& dataIndex) const
{
    return inventory[dataIndex]->getName();
}
const std::string& InventoryItem::getDescription(const int& dataIndex) const
{
    return inventory[dataIndex]->getDescription();

}
const int InventoryItem::getAttack(const int& dataIndex) const
{
    return inventory[dataIndex]->getAttack();
}
const int InventoryItem::getDefense(const int& dataIndex) const
{
    return inventory[dataIndex]->getDefense();
}

bool InventoryItem::usable(const int& dataIndex)
{
    return inventory[dataIndex]->getUsable();
}

bool Item::getUsable()
{
    return usable;
}


void InventoryItem::displayInfo(const int& dataIndex)
{
    inventory[dataIndex]->displayInfo();
}

void InventoryItem::displayItems()
{
    std::cout << "==================================\n" <<
    "bag\n" <<
    "==================================\n";
    if (inventory.size() == 0) {
        std::cout << "Your Inventory is Empty" << std::endl;
    }
    for (int i = 0; i < inventory.size(); i++)
    {
        std::cout << i << ". " << inventory[i]->getName() << "\n";
    }
    std::cout << inventory.size() << ". Exit" << "\n";
}

int InventoryItem::inventorySize()
{
    int inventorySize = inventory.size();
    return inventorySize;
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
    std::cout <<"==================================\n" <<
    name << "\n" <<
    "==================================\n" << 
    "Description: " << description << "\n" <<
    "Attack: " << attack << "\n" << 
    "Defense: " << defense << "\n";
}

//Adders and Removers

void InventoryItem::addItem(const std::shared_ptr<Item> newItem)
{
    // inventory.push_back(newItem);
    inventory.push_back(newItem);
}

void InventoryItem::removeItem(const int& dataIndex)
{
    if (dataIndex >= 0 && dataIndex < inventory.size())
    {
        inventory[dataIndex].reset();
        inventory.erase(inventory.begin() + dataIndex);
    }    
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
        inventory[index]->setName(newName);
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
