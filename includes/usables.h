#pragma once

#include "item.h"

class Usables : public Item
{
public:
    Usables(const std::string& name, const std::string& description, int attack, int defense) 
    : Item(name, description, attack, defense) {}

};