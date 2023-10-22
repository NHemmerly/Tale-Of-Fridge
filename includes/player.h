#pragma once

#include <iostream>
#include "entity.h"

class Player : public Entity
{
    public:
        Player();

        Player(const std::string& name, const int& health, const int& attackStat, const int& defenseStat);

        //Delegations
        
};
