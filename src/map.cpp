#include "map.h"

Map::Map(const std::string& name, const std::string& description, const std::string& north,
         const std::string& south, const std::string& east, const std::string& west,
         const std::vector<std::shared_ptr<Item>>& items, const std::vector<Player>& players,
         const bool& visited)
    : name(name), description(description), north(north), south(south), east(east), west(west),
      items(items), players(players), visited(visited)
{}