#include <iostream>
#include <string>
#include <filesystem>

bool folderImageExists()
{
    std::filesystem::path path = "Pictures";
    if(!std::filesystem::exists(path))
        return false;

    return true;
}

namespace fs = std::filesystem;

std::string getPicFromFolder(const std::string& path)
{
    for (const auto& entry : fs::directory_iterator(path))
    {
        if (entry.is_regular_file())
        {
            return path;
        }
    }

    return "";
}

void printImage()
{
    if(folderImageExists() == true)
    {
        std::string path = getPicFromFolder("Pictures");
        std::string command = "kitty +kitten icat --place 30x15@1x1 " + path;  
        std::system(command.c_str());
    }
}

int main()
{
    printImage();
    return 0;
}
