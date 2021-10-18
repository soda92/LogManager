#include "Utils.hpp"
int main()
{
    std::string path = get_log_path();
    for (const auto &entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;
}