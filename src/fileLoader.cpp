#include "fileLoader.h"

void FileLoad::loadTextFile(const std::string& filepath)
{
    std::fstream txtFile;
    txtFile.open(filepath, std::ios::in);
    if(txtFile.is_open())
    {
        std::string text;
        while(getline(txtFile, text))
        {
            std::cout << text << std::endl;
        }
        txtFile.close();
    }

}
