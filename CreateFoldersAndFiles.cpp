#include "Utils.hpp"
#include <boost/filesystem.hpp>

int main(int argc, char **argv)
{
    if (argc == 0)
    {
        return 0;
    }
    int input = 0;
    if (argc == 1)
    {
        input = 6;
    }
    else
    {
        input = to_int(argv[1]);
    }

    auto current = boost::filesystem::current_path();
    current /= "/Logs/";
    boost::filesystem::create_directory(current);
    auto dirnames = get_dir_names(10);
    for (auto dirname : dirnames)
    {
        auto p = current;
        p /= dirname + "/";
        boost::filesystem::create_directory(p);
        auto p2 = p;
        p2 += "log.txt";
        std::ofstream file;
        file.open(p2.c_str(), std::ios::out);
        p /= "log/";
        boost::filesystem::create_directory(p);
        p /= "loglog.txt";
        file.close();
        file.open(p.c_str(), std::ios::out);
        std::cout << p << '\n';
    }
    return 0;
}