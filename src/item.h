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

std::vector<ItemData*> itemInitializationData;

class InventoryItem {
public:
    InventoryItem(int dataIndex) : dataIndex(dataIndex) {}

    //Getters
    const std::string& getName() const;
    const std::string& getDescription() const;
    const int getAttack() const;
    const int getDefense() const;

    //Setters
    void setName(int index, const std::string& newName);
    void setDescription(int index, const std::string& newDescription);
    void setAttack(int index, const int& newAttack);
    void setDefense(int index, const int& newDefense);
private:
    int dataIndex;
    std::vector<InventoryItem> inventory;
};


