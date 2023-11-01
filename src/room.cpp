#include "room.h"

/*--Publix----------------------------------------------------------------------------------------------------------------*/

Room::Room(const std::string& name, const std::string& description, const std::map<std::string, std::string>& directions,
         const std::vector<std::shared_ptr<Item>>& items, const std::vector<Player>& players,
         const bool& visited, const std::vector<std::string>& story)
    : name(name), description(description), directions(directions),
      items(items), players(players), visited(visited), story(story)
{}

/*--Getters-Setters--------------------------------------------------------------------------------------------------------*/

const std::string& Room::getName()
{
  return name;
}

std::string Room::makeName(const int& part)
{
  std::string inputHandler;
  lineByLine(story[part]);
  std::cin >> inputHandler;
  return inputHandler;
}

/*--TextControl--------------------------------------------------------------------------------------------------------------*/

void Room::writeText(const int& part)
{
  lineByLine(story[part]);
}

void Room::printDescription()
{
  std::cout << "==================================\n" <<
  name << "\n" <<
  "==================================\n";
  lineByLine(description);
  std::cout << "==================================\n";
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

/*--Lookers-Takers-----------------------------------------------------------------------------------------------------------*/

void Room::removeItem(const std::shared_ptr<Item> goneItem)
{
  auto it = std::find(items.begin(), items.end(), goneItem);
  items.erase(it);
}

const std::shared_ptr<Item> Room::takeItem(const std::string& itemName)
{
  for (const std::shared_ptr<Item> item : items)
  {
    if (item->getName() == itemName)
    {
      return item;
    }
  }
  std::cout << "Where'd you come up with that? There's no " <<
  itemName << " in here.\n";
  return nullptr;
}

void Room::lookItem(const std::string& itemName)
{
  for (const std::shared_ptr<Item> item : items)
  {
    if (item->getName() == itemName)
    {
      item->displayInfo();
      return;
    }
  }

  std::cout << "Hmm there doesnt seem to be a " << itemName <<
  " in this room." << "\n";

}

const Player& Room::lookMob(const std::string& mobName)
{
  for (const auto& mob : players)
  {
    if (mob.getName() == mobName)
    {
      return mob;
    }
  }

  static const Player nullPlayer;
  std::cout << "Hmm there doesn't seem to be a " << mobName << 
  " in this room." << "\n";
  return nullPlayer;
}

/*--Privates------------------------------------------------------------------------------------------------------------------*/

/*--TextControl--------------------------------------------------------------------------------------------------------------*/

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



