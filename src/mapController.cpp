#include "mapController.h"


/*--Publix-----------------------------------------------------------------------------------------------------*/
MapController::MapController(){}

void MapController::buildMap()
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

const std::string& MapController::getMapName()
{
    return maps[0]->getName();
}

const std::shared_ptr<Room> MapController::findRoom(const std::string& roomName)
{
    for (const auto& room : maps)
    {
        if (room->getName() == roomName)
        {
            return room;
        }
    }

    std::cout << roomName <<"Room not found!" << "\n";
    return nullptr; 
}

/*--Privates-----------------------------------------------------------------------------------------------*/

/*--FS-Control---------------------------------------------------------------------------------------------*/

const std::string MapController::fileSearch(const std::string& dirPath, const std::string& name)
{
    std::filesystem::path directory = dirPath;
    std::string fileName = name + ".yaml";

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

/*--Loaders------------------------------------------------------------------------------------------------*/

const YAML::Node MapController::loadYml(const std::string& filepath)
{
    //load yaml
    YAML::Node config = YAML::LoadFile(filepath);
    return config;  
}


const std::map<std::string, std::string> MapController::loadDirections(const YAML::Node& room)
{
    std::map<std::string, std::string> directions;
    if (room["directions"] && room["directions"].IsMap() && room["directions"].IsDefined())
    {
        for (const auto& directionNode : room["directions"])
        {
            directions[directionNode.first.as<std::string>()] = directionNode.second.as<std::string>();
        }
    }
    return directions;
}

const std::vector<std::shared_ptr<Item>> MapController::loadItems(const YAML::Node& room)
{
    std::vector<std::shared_ptr<Item>> items;
    if (room["items"] && room["items"].IsSequence() && room["items"].IsDefined())
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

const std::vector<std::string> MapController::loadStory(const YAML::Node& room)
{
    std::vector<std::string> story;
    if (room["story"] && room["story"].IsSequence())
    {
        const YAML::Node& storiesNode = room["story"];

        for (const auto& storyNode : storiesNode)
        {
            if(storyNode.IsScalar())
            {
                std::string newObjectName = fileSearch("yamlAssets/story/", storyNode.as<std::string>());
                const YAML::Node config = loadYml(newObjectName);
                story.push_back(config["storyText"].as<std::string>());
            }
        }
    }
    return story;
}

const std::vector<Player> MapController::loadPlayers(const YAML::Node& room)
{
    std::vector<Player> players;
    if (room["characters"] && room["characters"].IsSequence() && room["characters"].IsDefined())
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

/*--Creators------------------------------------------------------------------------------------------------*/

const std::shared_ptr<Weapon> MapController::createWeapon(const std::string& filepath)
{
    const YAML::Node config = loadYml(filepath);

    std::string name = config["weapon"]["name"].as<std::string>();
    std::string description = config["weapon"]["description"].as<std::string>();
    int attack = config["weapon"]["attack"].as<int>();
    int defense = config["weapon"]["attack"].as<int>();

    std::shared_ptr<Weapon> newWeapon = std::make_shared<Weapon>(name, description, attack, defense);
    return newWeapon;
}

const std::shared_ptr<Item> MapController::createItem(const std::string& filepath)
{
    const YAML::Node config = loadYml(filepath);

    std::string name = config["item"]["name"].as<std::string>();
    std::string description = config["item"]["description"].as<std::string>();
    int attack = config["item"]["attack"].as<int>();
    int defense = config["item"]["defense"].as<int>();

    std::shared_ptr<Item> newItem = std::make_shared<Item>(name, description, attack, defense);
    return newItem;
}

const Player MapController::createPlayer(const std::string& filepath)
{
    const YAML::Node player = loadYml(filepath);

    std::string name = player["player"]["name"].as<std::string>();
    int health = player["player"]["health"].as<int>();
    int attackStat = player["player"]["attackStat"].as<int>();
    int defenseStat = player["player"]["defenseStat"].as<int>();

    Player newPlayer(name, health, attackStat, defenseStat);
    return newPlayer;
}

const std::shared_ptr<Room> MapController::buildRoom(const std::string& filepath)
{
    try {
        const YAML::Node room = loadYml(filepath);

        std::string name = room["name"].as<std::string>();
        std::string description = room["description"].as<std::string>();
        std::map<std::string, std::string> directions = loadDirections(room);
        std::vector<std::shared_ptr<Item>> items = loadItems(room);
        std::vector<Player> characters = loadPlayers(room);
        bool visited = room["visited"].as<bool>();
        std::vector<std::string> story = loadStory(room);

        std::shared_ptr<Room> newRoom = std::make_shared<Room>(name, description, directions, items, characters, visited, story);
        return newRoom;
    } catch (const YAML::BadFile& e) {
        std::cerr << "Can't load yaml :( " << filepath << "\n";

        return nullptr;
    }
}



