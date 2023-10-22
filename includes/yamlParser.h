#pragma once

#include <filesystem>
#include <fstream>
#include "yaml.h"
#include "item.h"
#include "player.h"
#include "weapons.h"
#include "map.h"

class Parser
{
    public:
        Parser();
        const YAML::Node loadYml(const std::string& filepath);
        const std::shared_ptr<Weapon> createWeapon(const std::string& filepath);
        const std::shared_ptr<Item> createItem(const std::string& filepath);
        const Player createPlayer(const std::string& filepath);
        void buildMap();
    private:
        const Map buildRoom(const std::string& filepath);
        const std::vector<std::shared_ptr<Item>> loadItems(const YAML::Node& room);
        const std::vector<Player> loadPlayers(const YAML::Node& room);
        const std::string fileSearch(const std::string& dirPath, const std::string& name);

        

};