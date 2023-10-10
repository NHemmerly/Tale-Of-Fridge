#pragma once

#include <iostream>
#include <vector>
#include <string>

struct ItemData {
    int itemID;
    std::string name;
    std::string itemDescription;
    int attack;
    int defense;
};

class Item {
public:
    //Item constructor
    Item(const std::string& name) : name(name) {}

    // Getter methods
    const std::string& getName() const;
    const std::string& getDescription() const;
    const int getAttack() const;
    const int getDefense() const;

    //Setters
    void setName(const std::string& newName);
private:
    std::string name;
};

class InventoryItem {
public:
    InventoryItem();

    void addItem(const Item& newItem);

    //Getters
    const std::string& getName(const int& dataIndex) const;
    const std::string& getDescription(const int& dataIndex) const;
    const int getAttack(const int& dataIndex) const;
    const int getDefense(const int& dataIndex) const;

    //Setters
    void setName(int index, const std::string& newName);
    void setDescription(int index, const std::string& newDescription);
    void setAttack(int index, const int& newAttack);
    void setDefense(int index, const int& newDefense);
private:
    int dataIndex;
    std::vector<Item> inventory;
};


