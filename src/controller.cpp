#include "controller.h"

//Globals?
bool menuOn = false;
bool displaying = false;
bool displayingItem = false;

Controller::Controller()
{
    this->verbs = 
    {
        "go", "take", "use"
    };
    this->nouns = 
    {
        "north", "south", "east", "west"
    };
    this->keyWords =
    {
        "menu", "exit", "bag"
    };
    this->menu = 
    {
        "bag", "status", "save", "exit", "quit game" 
    };
}

int Controller::runGame()
{
    mapController.buildMap();
    std::shared_ptr<Player> loadPlayer = mapController.maps[0]->players[0];
    player = loadPlayer;
    std::cout << player->getName() << "\n";
    player->setName(mapController.maps[0]->players[0]->getName());

    bool gameIsRunning = true;


    while(gameIsRunning)
    {
        //Intro
        std::string inputHandler;
        FileLoad::writeText("textAssets/story1.txt", 0);
        std::cin >> inputHandler;
        player->setName(inputHandler);
        std::cout << mapController.maps[0]->players[0]->getName() << "\n";
        FileLoad::writeText("textAssets/iRemember.txt", 0); 
        std::cout << player->getName() << std::endl;
        FileLoad::writeText("textAssets/myName.txt", 0);
        std::cin >> inputHandler;

        player->inventory.addItem(inputHandler, FileLoad::returnText("textAssets/itemDescriptions/theBlade.txt"), 3, 0, 1);
        FileLoad::dialogText("textAssets/1/1.txt", player->inventory.getName(0));
        player->inventory.addItem("Potion", "A healing potion", -10, 0);
        player->inventory.addItem("Pain", "Owie ouch ow", 20, 0);
        std::cout << mapController.getMapName() << "\n";

        bool inputLoop = true;

            while(inputLoop)
            {
                std::cin >> inputHandler;
                parseCommand(inputHandler);
                std::cout << inputLoop << "\n";
                inputLoop = getGameState();
            }
        return 0;
    }
    return 1;
}

std::shared_ptr<Controller> Controller::createInstance()
{
    return std::make_shared<Controller>();
}


//Publix
void Controller::parseCommand(const std::string& input)
{
    //Split input into a vector of words
    std::vector<std::string> words = splitString(input);

    if (words.empty())
    {
        std::cout << "Please enter a command." << std::endl;
        return;
    }

    //convert first word to lowercase
    std::string verb = words[0];
    std::transform(verb.begin(), verb.end(), verb.begin(), ::tolower);

    if ( std::find(keyWords.begin(), keyWords.end(), verb) != keyWords.end())
    {

        if (verb.compare("menu") == 0)
        {
            menuFlow();
        } 
    }


}
//Privates
void Controller::displayMenu(){
    std::cout << "==================================\n" <<
    "Menu\n" << "Enter a number\n" <<
    "==================================\n";
    for (int i = 0; i < menu.size(); i++)
    {
        std::cout << i << ". " << menu[i] << std::endl;
    }
    std::cout << "==================================\n";
}

void Controller::parseMenu(const int& input)
{
    switch (input)
    {
        case 0:
        {
            // Bag
            player->inventory.displayItems();
            bagFlow();
            break;
        }
        case 1:
        {
            player->displayInfo();
            statusFlow();
            break;
        }
        case 3:
        {
            // Exit
            exitMenu();
            break;
        }
        case 4:
        {
            quitGame();
            break;
        }
        default:
            break;
    }
}

bool Controller::getGameState()
{
    return gameState;
}

void Controller::quitGame()
{
    menuOn = false;
    gameState = false;
}

void Controller::menuFlow(){
    menuOn = true;
    int input = 0;
    std::string inputStr = "";  
    displayMenu();
    while (menuOn)
    {
        std::cin >> inputStr;
        input = convertInt(inputStr);
        if (input > menu.size() - 1 || input < 0)
        {
            std::cout << "Please enter one of the numbers above" << "\n";
            continue;
        }
        parseMenu(input);
    }

}

void Controller::exitMenu()
{
    menuOn = false;
}

void Controller::exitItem()
{
    displayingItem = false;
    player->inventory.displayItems();
}

void Controller::exitStatus()
{
    displaying = false;
    displayMenu();
}

void Controller::bagFlow()
{
    displaying = true;
    int input = 0;
    std::string inputStr = "";
    while(displaying)
    {
        int inventorySize = player->inventory.inventorySize();
        std::cin >> inputStr;
        input = convertInt(inputStr);
        if (input == inventorySize)
        {
            exitStatus();
        } else if (input > inventorySize)
        {
            std::cout << "Please enter a valid item#" << "\n";
        } else 
        {
            itemFlow(input);
        }
    }
}

void Controller::itemFlow(const int& dataIndex)
{
    player->inventory.displayInfo(dataIndex);
    int input = 0;
    std::string inputString = "";
    displayingItem = true;
    while(displayingItem)
    {
        std::cin >> inputString;
        input = convertInt(inputString);
        if (input != 0 && input != 1)
        {
            std::cout << "Type 0 to exit" << "\n";
            continue;
        } else if (input == 0)
        {
            player->useItem(dataIndex);
        }
        exitItem();
        
    }
}

void Controller::statusFlow()
{
    int input = 0;
    std::string inputString = "";
    displaying = true;
    while(displaying)
    {
        std::cin >> inputString;
        input = convertInt(inputString);
        if (input != 0)
        {
            std::cout << "Type 0 to exit" << "\n";
            continue;
        }
        exitStatus();
        
    }
}

std::vector<std::string> Controller::splitString(const std::string& input)
{
    std::vector<std::string> words;
    std::string word;
    for (char c : input)
    {
        if (c == ' ')
        {
            if (!word.empty()) 
            {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty())
    {
        words.push_back(word);
    }
    return words;
}

//Utility
int Controller::convertInt(const std::string& inputStr)
{
    int input;
    try 
    {
        //Attempt to convert input string to integer
        input = std::stoi(inputStr);
    } catch (const std::invalid_argument&)
    {
        std::cerr << "Please enter a number" << "\n";
        return 999;
    }
    return input;
}


