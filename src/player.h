#pragma once

#include <iostream>

class Player
{
    public:
        Player(const std::string& name);

        const std::string& getName() const;
        

    private:
        std::string name;
        int health = 100;
        int attackStat = 1;
        int defenseStat = 1;
};