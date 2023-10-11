#include "controller.h"

//Globals?
bool menuOn = false;

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
            displayMenu();
        }
    }


}
//Privates
void Controller::displayMenu(){
    menuOn = true;
    std::cout << "==================================\n" <<
    "Menu\n" <<
    "==================================\n";
    for (int i = 0; i < menu.size(); i++)
    {
        std::cout << i << ". " << menu[i] << std::endl;
    }
    std::cout << "==================================\n";
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
