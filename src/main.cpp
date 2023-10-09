#include <iostream>
#include "player.h"
#include "fileLoader.h"



int main()
{
    Player player;

    bool gameIsRunning = true;
    /*GameLoop*/
    while(gameIsRunning)
    {
        std::string inputHandler;
        FileLoad::writeText("textAssets/story1.txt", 0);
        std::cin >> inputHandler;
        player.setName(inputHandler);
        FileLoad::writeText("textAssets/iRemember.txt", 0); 
        std::cout << player.getName() << std::endl;
        FileLoad::writeText("textAssets/myName.txt", 0);
        std::cin >> inputHandler;
        

    };
}
