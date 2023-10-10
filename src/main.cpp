#include <iostream>
#include "player.h"
#include "fileLoader.h"
#include "item.h"



int main()
{
    Player player;
    InventoryItem inventory;

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

        inventory.addItem(Item(inputHandler, FileLoad::returnText("textAssets/itemDescriptions/theBlade.txt"), 3, 0));
        std::cout << inventory.getName(0) << std::endl;
        inventory.addItem(Item("testItem", "testDescription", 3, 1));
        std::cout << inventory.getDescription(0) << std::endl;
        inventory.displayInfo(0);

        

    };
}
