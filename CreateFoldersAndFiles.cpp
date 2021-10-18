#include "Utils.hpp"

#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    if (argc == 0)
    {
        return 0;
    }
    std::string input = "";
    if (argc == 1)
    {
        input = "6";
    }
    else
    {
        input = argv[1];
    }
    std::stringstream ss(input);
    int folderNumber = 0;
    ss >> folderNumber;

    fs::create_directory("Logs");
    for (int i = 0; i < folderNumber; i++)
    {
    }
}