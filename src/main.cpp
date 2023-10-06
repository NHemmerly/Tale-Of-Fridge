#include <iostream>
#include "player.h"
#include "fileLoader.h"



int main()
{
    Player kneel;

    bool gameIsRunning = true;
    /*GameLoop*/
    while(gameIsRunning)
    {
        std::string inputHandler;
        FileLoad::loadTextFile("textAssets/story1.txt");
        std::cin >> inputHandler;
        kneel.setName(inputHandler);
        FileLoad::loadTextFile("textAssets/welcome.txt"); 
        std::cout << kneel.getName() << std::endl;

    };
}
