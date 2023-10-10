#include "fileLoader.h"

using namespace std::this_thread;
using namespace std::chrono;

//Publics
void FileLoad::writeText(const std::string& filepath, int options)
{
    std::fstream txtFile;
    txtFile.open(filepath, std::ios::in);
    if(txtFile.is_open())
    {
        std::string text;
        switch(options){
            case 0:
            {
                while (std::getline(txtFile, text)) {
                    // sleep_for(seconds(1));
                    std::cout << text << std::endl;
                }
                break;
            }
            case 1:
            {
                std::string content((std::istreambuf_iterator<char>(txtFile)), (std::istreambuf_iterator<char>()));
                std::cout << content << std::endl;
                break;
            }
            default:
                std::cout << "invalid option" << std::endl;
        }
        txtFile.close();
    }
}

const std::string FileLoad::returnText(const std::string& filepath)
{
    std::fstream txtFile;
    txtFile.open(filepath, std::ios::in);
    if(txtFile.is_open())
    {
        return std::string((std::istreambuf_iterator<char>(txtFile)), (std::istreambuf_iterator<char>()));
    } else{
        return "Failed to load";
    }
}

