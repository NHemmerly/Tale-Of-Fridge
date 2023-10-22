#include <iostream>
#include "controller.h"



int main()
{
    Controller controller;
    std::shared_ptr<Controller> game = controller.createInstance();
    
    game->runGame();
    
    return 0;
}
