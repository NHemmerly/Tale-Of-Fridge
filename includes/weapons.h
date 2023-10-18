#pragma once

#include "item.h"

class Weapon : public Item
{
public:
    Weapon(const std::string& name, const std::string& description, int attack, int defense) 
    : Item(name, description, attack, defense){}
    void displayInfo() override;
private:
    



};