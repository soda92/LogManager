#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>
#include <iostream>
#include <regex>

#include <fmt/core.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <INIReader.h>

int to_int(std::string str)
{
    int value = boost::lexical_cast<int>(str);
    return value;
}

std::string get_log_path()
{
    INIReader reader("config/path.ini");
    std::string dir = reader.Get("path", "dir", "");
    std::string path = std::regex_replace(dir, std::regex("\\"), "/");
    return path;
}

std::vector<int> get_date(int offset)
{
    using namespace boost::gregorian;
    date today(day_clock::local_day());
    date_duration dd(offset);
    date d = today - dd;

    std::vector<int> ret;
    ret.push_back(d.year());
    ret.push_back(d.month().as_number());
    ret.push_back(d.day().as_number());
    return ret;
}

std::vector<std::string> get_dates(int days)
{
    std::vector<std::string> ret;
    for (int i = 0; i < days; i++)
    {
        std::vector<int> vecDate = get_date(i);
        std::string strDate = fmt::format("{:02}{:02}", vecDate[1], vecDate[2]);
        ret.push_back(strDate);
    }
    return ret;
}

std::vector<int> convert_dates_to_days(std::vector<std::string> dates)
{
    std::vector<int> ret;
    int year = get_date(0)[0];
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
