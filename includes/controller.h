#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include "item.h"
#include "player.h"
#include "mapController.h"

class Controller {
public:
    Controller();

    std::shared_ptr<Controller> createInstance();

    int runGame();

private:
    //Input Processing
    void parseCommand(const std::string& input);
    int convertInt(const std::string& inputStr);
    std::vector<std::string> splitString(const std::string& input);
    void parseMenu(const int& input);
    //Gamestate Controls
    void quitGame();
    bool gameState = true;
    //Menu and Bag Flow
    void displayMenu();
    void menuFlow();
    void exitMenu();
    void bagFlow();
    void itemFlow(const int& dataIndex);
    void exitItem();
    void statusFlow();
    void exitStatus();
    //Look
    void lookRoom();
    //Go
    void goDirection(const std::string& direction);
    //Fight
    void fightMob(const std::string& mobName);
    void combatFlow(const Player& mob);
    void displayCombat(const Player& mob);
    //Keywords
    std::vector<std::string> keyWords;
    std::vector<std::string> menu;
    std::vector<std::string> combat;
    //Objects
    Player player;
    MapController mapController;
};
