#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Item {
public:
    //Item constructor
    Item(const std::string& name, const std::string& description, int attack, int defense)
        : name(name), description(description), attack(attack), defense(defense) {}

    // Getter methods
    const std::string& getName() const;
    const std::string& getDescription() const;
    const int getAttack() const;
    const int getDefense() const;
    virtual void displayInfo();

    //Setters
    void setName(const std::string& newName);
protected:
    std::string name;
    std::string description;
    int attack;
    int defense;
};

class InventoryItem {
public:
    InventoryItem();

    void addItem(const std::string& name, const std::string& description, int attack, int defense, int flag = 0);
    void removeItem(const int& dataIndex);

    //Getters
    const std::string& getName(const int& dataIndex) const;
    const std::string& getDescription(const int& dataIndex) const;
    const int getAttack(const int& dataIndex) const;
    const int getDefense(const int& dataIndex) const;
    void displayInfo(const int& dataIndex);
    void displayItems();
    int inventorySize();

    //Setters
    void setName(int index, const std::string& newName);
    void setDescription(int index, const std::string& newDescription);
    void setAttack(int index, const int& newAttack);
    void setDefense(int index, const int& newDefense);


protected:
    int dataIndex;
    std::vector<std::shared_ptr<Item>> inventory;
};


