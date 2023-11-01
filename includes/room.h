#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <map>
#include <algorithm>
#include "player.h"

class Room
{
public:
  Room(const std::string& name, const std::string& description, const std::map<std::string, std::string>& directions,
      const std::vector<std::shared_ptr<Item>>& items, const std::vector<Player>& players,
      const bool& visited, const std::vector<std::string>& story);

  std::string makeName(const int& part);
  const std::string& getName();

  //TextControl
  void writeText(const int& part);
  void printDescription();
  void playRoom();
  //LookersTakers
  const std::shared_ptr<Item> takeItem(const std::string& itemName);
  void removeItem(const std::shared_ptr<Item> goneItem);
  const Player& lookMob(const std::string& mobName);
  void lookItem(const std::string& itemName);
  //Objects
  std::map<std::string, std::string> directions;
  std::vector<std::shared_ptr<Item>> items;
  std::vector<std::string> story;
  std::vector<Player> players;
private:
  //TextControl
  void lineByLine(const std::string& text);
  //Objects
  std::string description;
  std::string name;
  bool visited;
};
