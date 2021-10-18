#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <fstream>

std::string get_log_path()
{
    std::ifstream file;
    file.open("path.ini", std::ios::in);
    std::string line;
    std::getline(file, line);
    return line;
}
#endif