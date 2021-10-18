#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

int main()
{
    std::ifstream file;
    file.open("path.ini", std::ios::in);
    std::string line;
    std::getline(file, line);
fs::create_directory("sandbox

    std::string path = "/path/to/directory";
    for (const auto &entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}