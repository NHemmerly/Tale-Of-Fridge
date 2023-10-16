#include "controller.h"

//Globals?
bool menuOn = false;
bool displayingBag = false;
bool displayingItem = false;
bool displayingStatus = false;

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
        "bag", "use", "status", "save", "exit" 
    };
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
        case 2:
        {
            getShowStatus();
            statusFlow();
            break;
        }
        case 4:
        {
            // Exit
            exitMenu();
            break;
        }
        default:
            break;
    }
}

void Controller::menuFlow(){
    menuOn = true;
    int input;
    std::string inputStr;  
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

void Controller::exitBag()
{
    displayingBag = false;
    displayMenu();
}

void Controller::exitItem()
{
    displayingItem = false;
    getPlayerInventory();
}

void Controller::exitStatus()
{
    displayingStatus = false;
    displayMenu();
}

void Controller::bagFlow()
{
    displayingBag = true;
    int input;
    std::string inputStr;
    int inventorySize = getInventorySize();
    while(displayingBag)
    {
        std::cin >> inputStr;
        input = convertInt(inputStr);
        if (input == inventorySize)
        {
            exitBag();
        } else if (input > inventorySize)
        {
            std::cout << "Please enter a valid item#" << "\n";
        } else 
        {
            getDisplayInfo(input);
            itemFlow();
        }
    }
}

void Controller::itemFlow()
{
    int input;
    std::string inputString;
    displayingItem = true;
    while(displayingItem)
    {
        std::cin >> inputString;
        input = convertInt(inputString);
        if (input != 0)
        {
            std::cout << "Type 0 to exit" << "\n";
            continue;
        }
        exitItem();
        
    }
}

void Controller::statusFlow()
{
    int input;
    std::string inputString;
    displayingStatus = true;
    while(displayingStatus)
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
const int& Controller::getInventorySize() const
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

void Controller::getAddItem(const Item& newItem)
{
    player.getAddItem(newItem);
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
