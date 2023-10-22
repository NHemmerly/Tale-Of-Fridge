#pragma once

#include <filesystem>
#include <fstream>
#include "yaml.h"
#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/parse.h"
#include "yaml-cpp/node/emit.h"
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

        const std::string& getMapName();
    private:
        std::vector<std::shared_ptr<Map>> maps;
        const std::shared_ptr<Map> buildRoom(const std::string& filepath);
        const std::vector<std::shared_ptr<Item>> loadItems(const YAML::Node& room);
        const std::vector<Player> loadPlayers(const YAML::Node& room);
        const std::string fileSearch(const std::string& dirPath, const std::string& name);

        

};