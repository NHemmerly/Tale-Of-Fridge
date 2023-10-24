#include "room.h"

Room::Room(const std::string& name, const std::string& description, const std::string& north,
         const std::string& south, const std::string& east, const std::string& west,
         const std::vector<std::shared_ptr<Item>>& items, const std::vector<std::shared_ptr<Player>>& players,
         const bool& visited, const std::vector<std::string>& story)
    : name(name), description(description), north(north), south(south), east(east), west(west),
      items(items), players(players), visited(visited), story(story)
{}

const std::string& Room::getName()
{
    return name;
}