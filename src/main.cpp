#include <iostream>
#include "player.h"
#include "fileLoader.h"
#include "item.h"
#include "controller.h"



int main()
{
    Controller controller;
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

        player.getAddItem(Item(inputHandler, FileLoad::returnText("textAssets/itemDescriptions/theBlade.txt"), 3, 0));
        FileLoad::dialogText("textAssets/1/1.txt", player.getItemName(0));
        player.getAddItem(Item("Potion", "A healing potion", -10, 0));
        std::cin >> inputHandler;
        controller.parseCommand(inputHandler);

        

    };
}
