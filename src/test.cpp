#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string verb = "GO";
    for(char& c : verb) {
        tolower(c);
    }

    std::cout << verb << std::endl;

    std::transform(verb.begin(), verb.end(), verb.begin(), ::tolower);
    std::cout << verb << std::endl;

    return 0;
}
