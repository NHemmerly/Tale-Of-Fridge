#include <iostream>
#include "player.h"
#include "fileLoader.h"
#include "item.h"
#include "controller.h"



int main()
{
    Controller controller;

    bool gameIsRunning = true;
    /*GameLoop*/
    while(gameIsRunning)
    {
        std::string inputHandler;
        FileLoad::writeText("textAssets/story1.txt", 0);
        std::cin >> inputHandler;
        controller.getSetName(inputHandler);
        FileLoad::writeText("textAssets/iRemember.txt", 0); 
        std::cout << controller.getGetName() << std::endl;
        FileLoad::writeText("textAssets/myName.txt", 0);
        std::cin >> inputHandler;

        controller.getAddItem(inputHandler, FileLoad::returnText("textAssets/itemDescriptions/theBlade.txt"), 3, 0);
        FileLoad::dialogText("textAssets/1/1.txt", controller.getItemName(0));
        controller.getAddItem("Potion", "A healing potion", -10, 0);
        controller.getAddItem("Pain", "Owie ouch ow", 20, 0);
        std::cin >> inputHandler;
        controller.parseCommand(inputHandler);

        

    };
}
