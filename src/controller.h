#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "item.h"
#include "player.h"

class Controller {
public:
    Controller();

    void parseCommand(const std::string& input);
    //Delegations
    void getSetName(const std::string& newName);
    const std::string& getGetName() const;
    void getPlayerInventory();
    void getAddItem(const Item& newItem);
    const std::string& getItemName(const int& dataIndex) const;

private:
    std::vector<std::string> splitString(const std::string& input);
    void displayMenu();
    void menuFlow();
    void exitMenu();
    void bagFlow();
    void exitBag();
    void parseMenu(const int& input);
    std::vector<std::string> verbs;
    std::vector<std::string> nouns;
    std::vector<std::string> keyWords;
    std::vector<std::string> menu;
    //Delegations
    Player player;
    const int& getInventorySize() const;


};