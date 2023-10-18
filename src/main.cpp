#include <iostream>
#include "player.h"
#include "fileLoader.h"
#include "item.h"
#include "controller.h"



int main()
{
    Controller controller;
    std::shared_ptr<Controller> game = controller.createInstance();

    bool gameIsRunning = true;
    
    /*GameLoop*/
    while(gameIsRunning)
    {
        //Intro
        std::string inputHandler;
        FileLoad::writeText("textAssets/story1.txt", 0);
        std::cin >> inputHandler;
        game->getSetName(inputHandler);
        FileLoad::writeText("textAssets/iRemember.txt", 0); 
        std::cout << game->getGetName() << std::endl;
        FileLoad::writeText("textAssets/myName.txt", 0);
        std::cin >> inputHandler;

        game->getAddItem(inputHandler, FileLoad::returnText("textAssets/itemDescriptions/theBlade.txt"), 3, 0, 1);
        FileLoad::dialogText("textAssets/1/1.txt", game->getItemName(0));
        game->getAddItem("Potion", "A healing potion", -10, 0);
        game->getAddItem("Pain", "Owie ouch ow", 20, 0);

        bool inputLoop = true;

        while(inputLoop)
        {
            std::cin >> inputHandler;
            game->parseCommand(inputHandler);
            std::cout << inputLoop << "\n";
            inputLoop = game->getGameState();
        }
        return 0;

    };
}
