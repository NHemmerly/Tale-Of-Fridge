#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <algorithm>
#include "player.h"

class Room
{
public:
  Room(const std::string& name, const std::string& description, const std::string& north,
      const std::string& south, const std::string& east, const std::string& west,
      const std::vector<std::shared_ptr<Item>>& items, const std::vector<std::shared_ptr<Player>>& players,
      const bool& visited, const std::vector<std::string>& story);

  const std::string& getName();

  
  std::vector<std::shared_ptr<Player>> players;
  std::vector<std::string> story;
  void playRoom();
  std::string makeName(const int& part);
  void writeText(const int& part);
  void printDescription();
  void lookItem(const std::string& itemName);
  const std::shared_ptr<Item> takeItem(const std::string& itemName);
  std::vector<std::shared_ptr<Item>> items;
  void removeItem(const std::shared_ptr<Item> goneItem);
private:
  void lineByLine(const std::string& text);
  std::string name;
  std::string description;
  std::string north;
  std::string south;
  std::string east;
  std::string west;
  bool visited;
};