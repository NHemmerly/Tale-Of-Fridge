#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include "fileLoader.h"
#include "item.h"
#include "player.h"
#include "mapController.h"

class Controller {
public:
    Controller();

    std::shared_ptr<Controller> createInstance();

    int runGame();
    void parseCommand(const std::string& input);
    bool getGameState();

private:
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
    
    int convertInt(const std::string& inputStr);
    void parseMenu(const int& input);
    std::vector<std::string> verbs;
    std::vector<std::string> nouns;
    std::vector<std::string> keyWords;
    std::vector<std::string> menu;
    bool gameState = true;
    std::shared_ptr<Player> player;
    MapController mapController;
};