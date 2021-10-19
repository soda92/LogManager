#include "Utils.hpp"
#include <boost/date_time/gregorian/greg_date.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
using boost::filesystem::canonical;
using boost::filesystem::directory_iterator;
using boost::filesystem::is_directory;
using boost::filesystem::path;
using boost::filesystem::remove;
using boost::gregorian::date;
using boost::gregorian::day_clock;
using boost::gregorian::from_simple_string;
using std::cout;
using std::endl;

int calc_day_difference(std::string folder_name)
{
    auto curr_date = get_date(Clock::now());
    int year = curr_date[0], month = curr_date[1], day = curr_date[2];

    std::string month2 = folder_name.substr(4, 2),
                day2 = folder_name.substr(6, 2);
    std::string dateStr = fmt::format("{}-{}-{}", year, month2, day2);
    date a(from_simple_string(dateStr));
    date today = day_clock::local_day();
    return (today - a).days();
}

int log(std::string message)
{
    std::fstream file;
    file.open("program.log", std::ios::out | std::ios::app);
    file << message << "\n";
    return 0;
}

void remove_recursively(path p)
{
    directory_iterator it{p};
    while (it != directory_iterator{})
    {
        auto p = *it;
        if (is_directory(p))
        {
            remove_recursively(p);
            log(fmt::format("remove directory: {}", canonical(p).string()));
            remove(p);
        }
        else
        {
            log(fmt::format("remove file: {}", canonical(p).string()));
            remove(p);
        }
        it++;
    }
}

void remove_old_folder(path p)
{
    directory_iterator it{p};
    while (it != directory_iterator{})
    {
        auto p = *it;
        if (is_directory(p))
        {
            path p2(p);
            std::string folderName = p2.filename().string();
            // fmt::print("folderName: {}, diff: {}\n",
            //    folderName, calc_day_difference(folderName));
            if (calc_day_difference(folderName) > 7)
            {
                fmt::print("remove: {}\n", p2.string());
                remove_recursively(p2);
                log(fmt::format("remove directory: {}", canonical(p2).string()));
                remove(p2);
            }
        }
        it++;
    }
}

int main()
{
    auto p_str = get_log_path();
    path p(p_str);
    remove_old_folder(p);
    return 0;
}