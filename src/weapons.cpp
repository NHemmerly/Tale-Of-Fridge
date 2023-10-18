#include "weapons.h"

void Weapon::displayInfo()
{
    std::cout <<"==================================\n" <<
    name << "\n" <<
    "==================================\n" << 
    "Description: " << description << "\n" <<
    "Attack: " << attack << "\n" << 
    "Defense: " << defense << "\n" <<
    "1. exit" << "\n";
}