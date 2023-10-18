#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "item.h"

class FileLoad
{
public:
    static void writeText(const std::string& filepath, int options);
    static const std::string returnText(const std::string& filepath);
    static void dialogText(const std::string& filepath, const std::string& itemName);
};
