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
#include <filesystem>
#include <fmt/core.h>

#include <boost/date_time/gregorian/gregorian.hpp>

typedef std::chrono::system_clock Clock;
using namespace std::chrono_literals;
namespace fs = std::filesystem;

int to_int(std::string str)
{
    std::stringstream ss(str);
    int value = 0;
    ss >> value;
    return value;
}

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
    int year = get_date(Clock::now())[0];
    for (auto date : dates)
    {
        auto month = to_int(date.substr(0, 2));
        auto day = to_int(date.substr(2, std::string::npos));
        try
        {
            boost::gregorian::date d(year, month, day);
            int dayNumber = d.day_of_year();
            ret.push_back(dayNumber);
        }
        catch (std::out_of_range &e)
        {
            // Alternatively catch bad_year etc exceptions.
            std::cout << "Bad date: " << e.what() << std::endl;
        }
    }
    return ret;
}

std::vector<std::string> get_dir_names(int days_)
{
    auto dates = get_dates(days_);
    auto days = convert_dates_to_days(dates);
    std::vector<std::string> filenames;
    for (std::size_t i = 0; i < days.size(); i++)
    {
        std::string strDays = fmt::format("{:03}", days[i]);
        std::string filename = fmt::format("{}({})", strDays, dates[i]);
        filenames.push_back(filename);
    }
    return filenames;
}

#endif
