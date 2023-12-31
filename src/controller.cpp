#include "controller.h"

//Globals?
bool menuOn = false;
bool displaying = false;
bool displayingItem = false;

//Current Player location
std::shared_ptr<Room> currentRoom;
Controller::Controller()
{
    keyWords =
    {
        "go", "menu", "exit", "bag", "look", "take", "fight"
    };
    menu = 
    {
        "bag", "status", "save", "exit", "quit game" 
    };
    combat = 
    {
        "attack", "talk", "bag", "run"
    };
}

/*--Primary-Game-Loop------------------------------------------------------------------*/

int Controller::runGame()
{
    //--Load-all-rooms--
    mapController.buildMap();
    //--Set-starting-room-player--
    currentRoom = mapController.findRoom("Rubbled cobblestone path");
    Player loadPlayer = currentRoom->players[0];
    player = loadPlayer;
    player.setName(currentRoom->players[0].getName());

    bool gameIsRunning = true;

    while(gameIsRunning)
    {
        //Intro
        std::string inputHandler;
        player.setName(currentRoom->makeName(0));
        currentRoom->writeText(2);
        std::cout << player.getName() << "\n";

        player.inventory.addItem(currentRoom->items[0]);
        player.inventory.setName(0, currentRoom->makeName(1));
        std::cout << player.inventory.getName(0) << ": ";
        currentRoom->writeText(3);
        std::cout << mapController.getMapName() << "\n";

        bool inputLoop = true;

            while(inputLoop)
            {
                std::getline(std::cin, inputHandler);
                parseCommand(inputHandler);
                inputLoop = gameState;
            }
        return 0;
    }
    return 1;
}

std::shared_ptr<Controller> Controller::createInstance()
{
    return std::make_shared<Controller>();
}

/*--Game-State-Controls---------------------------------------------------------------------------*/

void Controller::quitGame()
{
    menuOn = false;
    gameState = false;
}

/*--Input-Processing------------------------------------------------------------------------------*/

void Controller::parseCommand(const std::string& input)
{
    //Split input into a vector of words
    std::vector<std::string> words = splitString(input);

    if (words.empty())
    {
        std::cout << "What would you like to do?" << std::endl;
        return;
    }

    //convert input string to lowercase
    for (std::string& word : words)
    {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    }

    std::string verb = words[0];
    if ( std::find(keyWords.begin(), keyWords.end(), verb) != keyWords.end())
    {
        //--Are-there-two-words?--
        if (words.size() > 1)
        {
            std::string object = words[1];
            if (verb.compare("go") == 0)
            {
                goDirection(object);
            }
            if (verb.compare("fight") == 0)
            {
                fightMob(object);
            }
        }

        if (verb.compare("menu") == 0)
        {

            menuFlow();
        } 
        if (verb.compare("look") == 0)
        {
            if (words.size() == 2)
            {
                currentRoom->lookItem(words[1]);
            } else {
                lookRoom();
            }
        }
        if (verb.compare("take") == 0)
        {
            if (words.size() == 2)
            {
                std::shared_ptr<Item> newItem = currentRoom->takeItem(words[1]);
                if (newItem)
                {
                    player.inventory.addItem(currentRoom->takeItem(words[1]));
                    currentRoom->removeItem(newItem);
                }
            } 
        }
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

int Controller::convertInt(const std::string& inputStr)
{
    int input;
    try 
    {
        //Attempt to convert input string to integer
        input = std::stoi(inputStr);
    } catch (const std::invalid_argument&)
    {
        return -1;
    }
    return input;
}

/*--Menus---------------------------------------------------------------------------*/

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
    if (input > menu.size() - 1 || input < 0)
    {
        std::cout << "Please enter one of the numbers above" << "\n";
    } else
    {
        switch (input)
        {
            case 0:
            {
                // Bag
                player.inventory.displayItems();
                bagFlow();
                break;
            }
            case 1:
            {
                player.displayInfo();
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
        parseMenu(input);
    }

}

void Controller::exitMenu()
{
    menuOn = false;
}

//--Bag-and-Items--

void Controller::bagFlow()
{
    displaying = true;
    int input = 0;
    std::string inputStr = "";
    while(displaying)
    {
        int inventorySize = player.inventory.inventorySize();
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
    player.inventory.displayInfo(dataIndex);
    int input = 0;
    std::string inputString = "";
    displayingItem = true;
    while(displayingItem)
    {
        std::cout << "0. use" <<  "\n" <<
        "1. exit" << "\n";
        std::cin >> inputString;
        input = convertInt(inputString);
        if (input != 0 && input != 1)
        {
            std::cout << "Type 0 to exit" << "\n";
            continue;
        } else if (input == 0)
        {
            player.useItem(dataIndex);
        }
        exitItem();
        
    }
}

void Controller::exitItem()
{
    displayingItem = false;
    player.inventory.displayItems();
}

//--Player-Status--

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

void Controller::exitStatus()
{
    displaying = false;
    displayMenu();
}

/*--Movement-and-Room-Control----------------------------------------------------------------------*/

//--Look--
void Controller::lookRoom()
{
    currentRoom->printDescription();
}

//--Go--
void Controller::goDirection(const std::string& direction)
{
    currentRoom = mapController.findRoom(currentRoom->directions[direction]);
    std::cout << currentRoom->getName() << "\n";
}

/*--Combat-------------------------------------------------------------------------------------------*/

//--Fight--
void Controller::fightMob(const std::string& mobName)
{
    const Player currentMob = currentRoom->lookMob(mobName);
    if (!(currentMob.getName() == "none"))
    {
        combatFlow(currentMob);
    }
}

void Controller::displayCombat(const Player& mob)
{
    std::cout << "==================================\n" <<
    mob.getName() << "  health: " << mob.getHP() << "/" << mob.getMaxHp() << "\n" <<
    "==================================\n" <<
    "1. " << combat[0] << "  2. " << combat[1] << "\n" <<
    "3. " << combat[2] << "     3. " << combat[3] << "\n" <<
    "==================================\n";
}

void Controller::combatFlow(const Player& mob)
{
    displayCombat(mob);
}
