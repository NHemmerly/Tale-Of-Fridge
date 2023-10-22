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
            getPlayerInventory();
            bagFlow();
            break;
        }
        case 1:
        {
            getShowStatus();
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
    getPlayerInventory();
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
        int inventorySize = getInventorySize();
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
    getDisplayInfo(dataIndex);
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
            player.useItem(dataIndex);
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

//Delegations

void Controller::getPlayerInventory()
{
    std::cout << "==================================\n" <<
    "bag\n" <<
    "==================================\n";
    player.getDisplayInventory();
}
int Controller::getInventorySize()
{
    return player.inventorySize();
}

void Controller::getSetName(const std::string& newName)
{
    player.setName(newName);
}

const std::string& Controller::getGetName() const 
{
    return player.getName();
}

void Controller::getAddItem(const std::string& name, const std::string& description, int attack, int defense, int flag)
{
    player.getAddItem(name, description, attack, defense, flag);
}

const std::string& Controller::getItemName(const int& dataIndex) const
{
    return player.getItemName(dataIndex);
}

void Controller::getDisplayInfo(const int& dataIndex)
{
    player.getDisplayItem(dataIndex);
}

void Controller::getShowStatus()
{
    player.displayInfo();
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

const std::string& Controller::getMapName()
{
    return parser.getMapName();
}

