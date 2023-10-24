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


//Story Handling

std::string Room::makeName(const int& part)
{
  std::string inputHandler;
  lineByLine(story[part]);
  std::cin >> inputHandler;
  return inputHandler;
}
void Room::writeText(const int& part)
{
  lineByLine(story[part]);
}
void Room::lineByLine(const std::string& text)
{
  std::stringstream textStream(text);
  std::string line;

  while (std::getline(textStream, line))
  {
    std::cout << line << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

void Room::playRoom()
{
  if (!visited)
  {
    for (const std::string& storyText : story)
    {
      lineByLine(storyText);
    }
  }
}