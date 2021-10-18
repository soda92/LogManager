#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
typedef std::chrono::system_clock Clock;
using namespace std::chrono_literals;

std::string get_log_path()
{
    std::ifstream file;
    file.open("path.ini", std::ios::in);
    std::string line;
    std::getline(file, line);
    auto equal_pos = line.find('=');
    auto path = line.substr(equal_pos, std::string::npos);
    std::string path2 = "";
    for (auto c : path)
    {
        if (c == ' ' || c == '=')
        {
            continue;
        }
        if (c == '\\')
        {
            path2 += "\\\\";
        }
        else
        {
            path2 += c;
        }
    }
    return path2;
}

std::vector<int> get_date(Clock::time_point time)
{
    std::time_t now_c = Clock::to_time_t(time);
    struct tm *parts = std::localtime(&now_c);

    std::vector<int> ret;
    ret.push_back(1900 + parts->tm_year);
    ret.push_back(1 + parts->tm_mon);
    ret.push_back(parts->tm_mday);
    return ret;
}

std::vector<std::string> get_dates(int days)
{
    std::vector<std::string> ret;
    auto now = Clock::now();
    auto date = now;
    for (int i = 0; i < days; i++)
    {
        date -= 24h;
        std::vector<int> vecDate = get_date(date);
        std::string folderName;
        std::stringstream out;
        out << std::setfill('0') << std::setw(2) << vecDate[1] << vecDate[2];
        ret.push_back(out.str());
    }
    return ret;
}

std::vector<int> convert_dates_to_days(std::vector<std::string> dates)
{
    std::vector<int> ret;
    return ret;
}

#endif
