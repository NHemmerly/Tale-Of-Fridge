#pragma once

#include <iostream>
#include <string>
#include "player.h"

class Map
{
public:
    Map(const std::string& name, const std::string& description, const std::string& north,
         const std::string& south, const std::string& east, const std::string& west,
         const std::vector<std::shared_ptr<Item>>& items, const std::vector<Player>& players,
         const bool& visited);

    
private:
    std::string name;
    std::string description;
    std::string north;
    std::string south;
    std::string east;
    std::string west;
    std::vector<std::shared_ptr<Item>> items;
    std::vector<Player> players;
    bool visited;
};