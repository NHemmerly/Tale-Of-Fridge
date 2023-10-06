#pragma once

#include <iostream>

class Player
{
    public:
        Player();

        const std::string& getName() const;
        const int& getHP() const;
        const int& getAttack() const;
        const int& getDefense() const;
        void setName(const std::string& name);
        void displayInfo();

    private:
        std::string name;
        int health = 100;
        int attackStat = 1;
        int defenseStat = 1;
};
