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
    void parseCommand(const std::string& input);
    bool getGameState();
    std::vector<std::string> splitString(const std::string& input);
    //Menu and Bag Flow
    void displayMenu();
    void menuFlow();
    void exitMenu();
    void bagFlow();
    void itemFlow(const int& dataIndex);
    void exitItem();
    void statusFlow();
    void exitStatus();
    void quitGame();
    //Look
    void lookRoom();
    //Go
    void goDirection(const std::string& direction);
    
    int convertInt(const std::string& inputStr);
    void parseMenu(const int& input);
    std::vector<std::string> keyWords;
    std::vector<std::string> menu;
    bool gameState = true;
    Player player;
    MapController mapController;
};
