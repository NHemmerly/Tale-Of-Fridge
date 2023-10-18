#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include "usables.h"
#include "player.h"

class Controller {
public:
    Controller();

    std::shared_ptr<Controller> createInstance();

    void parseCommand(const std::string& input);
    //Delegations
    void getSetName(const std::string& newName);
    const std::string& getGetName() const;
    void getPlayerInventory();
    void getAddItem(const std::string& name, const std::string& description, int attack, int defense);
    const std::string& getItemName(const int& dataIndex) const;
    bool getGameState();

private:
    std::vector<std::string> splitString(const std::string& input);
    void displayMenu();
    void menuFlow();
    void exitMenu();
    void bagFlow();
    void itemFlow(const int& dataIndex);
    void exitItem();
    void statusFlow();
    void exitStatus();
    void quitGame();
    int convertInt(const std::string& inputStr);
    void parseMenu(const int& input);
    std::vector<std::string> verbs;
    std::vector<std::string> nouns;
    std::vector<std::string> keyWords;
    std::vector<std::string> menu;
    bool gameState = true;
    //Delegations
    Player player;
    int getInventorySize();
    void getDisplayInfo(const int& dataIndex);
    void getShowStatus();


};