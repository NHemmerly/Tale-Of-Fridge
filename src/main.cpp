#include <iostream>
#include "player.h"



int main()
{
    Player kneel("Kneel");

    std::string test = kneel.getName();
    std::cout << test << std::endl;
}