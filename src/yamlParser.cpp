#include "yamlParser.h"

Parser::Parser(){}

const YAML::Node Parser::loadYml(const std::string& filepath)
{
    //load yaml
    YAML::Node config = YAML::LoadFile(filepath);
    return config;  
}

const std::string Parser::fileSearch(const std::string& dirPath, const std::string& name)
{
    std::filesystem::path directory = dirPath;
    std::string fileName = name + ".yml";

    if (std::filesystem::is_directory(directory))
    {
        return dirPath + fileName;
    } else
    {
        std::cout << "No File Found!" << "\n";
        return "No File Found!";
    }
    return "Directory Error";
}

const std::shared_ptr<Weapon> Parser::createWeapon(const std::string& filepath)
{
    const YAML::Node config = loadYml(filepath);

    std::string name = config["weapon"]["name"].as<std::string>();
    std::string description = config["weapon"]["description"].as<std::string>();
    int attack = config["weapon"]["attack"].as<int>();
    int defense = config["weapon"]["attack"].as<int>();

    std::shared_ptr<Weapon> newWeapon = std::make_shared<Weapon>(name, description, attack, defense);
    return newWeapon;
}

const std::shared_ptr<Item> Parser::createItem(const std::string& filepath)
{
    const YAML::Node config = loadYml(filepath);

    std::string name = config["item"]["name"].as<std::string>();
    std::string description = config["item"]["description"].as<std::string>();
    int attack = config["item"]["attack"].as<int>();
    int defense = config["item"]["attack"].as<int>();

    std::shared_ptr<Item> newItem = std::make_shared<Item>(name, description, attack, defense);
    return newItem;
}

const Player Parser::createPlayer(const std::string& filepath)
{
    const YAML::Node player = loadYml(filepath);

    std::string name = player["player"]["name"].as<std::string>();
    int health = player["player"]["health"].as<int>();
    int attackStat = player["player"]["attackStat"].as<int>();
    int defenseStat = player["player"]["defenseStat"].as<int>();

    Player newPlayer;
    return newPlayer;
}

const std::vector<std::shared_ptr<Item>> Parser::loadItems(const YAML::Node& room)
{
    std::vector<std::shared_ptr<Item>> items;
    if (room["items"] && room["items"].IsSequence())
    {
        const YAML::Node& itemsNode = room["items"];

        for (const auto& itemNode : itemsNode)
        {
            if (itemNode.IsScalar())
            {
                std::string newObjectName = fileSearch("yamlAssets/objects/", itemNode.as<std::string>());
                const YAML::Node config = loadYml(newObjectName);
                if (config["weapon"])
                {
                    items.push_back(createWeapon(newObjectName));
                } else if (config["item"])
                {
                    items.push_back(createItem(newObjectName));
                }
            }
        }
    } 
    return items;
}

const std::vector<Player> Parser::loadPlayers(const YAML::Node& room)
{
    std::vector<Player> players;
    if (room["characters"] && room["characters"].IsSequence())
    {
        const YAML::Node& playersNode = room["characters"];

        for (const auto& playerNode : playersNode)
        {
            if (playerNode.IsScalar())
            {
                std::string newObjectName = fileSearch("yamlAssets/objects/", playerNode.as<std::string>());
                const YAML::Node config = loadYml(newObjectName);
                players.push_back(createPlayer(newObjectName));
                
            }
        }
    }
    return players;        
}


const std::shared_ptr<Map> Parser::buildRoom(const std::string& filepath)
{
    try {
        const YAML::Node room = loadYml(filepath);

        std::string name = room["name"].as<std::string>();
        std::string description = room["description"].as<std::string>();
        std::string north = room["north"].as<std::string>();
        std::string south = room["south"].as<std::string>();
        std::string east = room["east"].as<std::string>();
        std::string west = room["west"].as<std::string>();
        std::vector<std::shared_ptr<Item>> items = loadItems(room);
        std::vector<Player> characters = loadPlayers(room);
        bool visited = room["visited"].as<bool>();

        std::shared_ptr<Map> newMap = std::make_shared<Map>(name, description, north, south, east, west, items, characters, visited);
        return newMap;
    } catch (const YAML::BadFile& e) {
        std::cerr << "Can't load yaml :( " << filepath << "\n";

        return nullptr;
    }
}

void Parser::buildMap()
{
    std::filesystem::path mapPath = "yamlAssets/rooms/";
    if (std::filesystem::is_directory(mapPath))
    {
        for (const auto& entry : std::filesystem::directory_iterator(mapPath))
        {
            maps.push_back(buildRoom(entry.path().string()));
        }
    }
}

const std::string& Parser::getMapName()
{
    return maps[0]->getName();
}

