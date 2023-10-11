#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Controller {
public:
    Controller();

    void parseCommand(const std::string& input);


private:
    std::vector<std::string> splitString(const std::string& input);
    void displayMenu();
    std::vector<std::string> verbs;
    std::vector<std::string> nouns;
    std::vector<std::string> keyWords;
    std::vector<std::string> menu;

};