#include "controller.h"

//Globals?
bool menuOn = false;
bool displayingBag = false;

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
    displayMenu();
    while (menuOn)
    {
        std::cin >> input;
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

void Controller::bagFlow()
{
    displayingBag = true;
    int input;
    int inventorySize = getInventorySize();
    while(displayingBag)
    {
        std::cin >> input;
        if (input == inventorySize)
        {
            exitBag();
        } else if (input > inventorySize)
        {
            std::cout << "Please enter a valid item#" << "\n";
        } else 
        {
            getDisplayInfo(input);
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

//Delegations

void Controller::getPlayerInventory()
{
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
