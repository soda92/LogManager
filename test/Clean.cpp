#include "Utils.hpp"
#include <boost/filesystem.hpp>
using namespace boost::filesystem;

void remove_recursively(path p)
{
    directory_iterator it{p};
    while (it != directory_iterator{})
    {
        auto p = *it;
        if (is_directory(p))
        {
            remove_recursively(p);
            std::cout << "remove directory: " << p << std::endl;
            remove(p);
        }
        else
        {
            std::cout << "remove file: " << p << std::endl;
            remove(p);
        }
        it++;
    }
}

int main()
{
    auto current = current_path();
    current /= "Logs/";
    remove_recursively(current);
    return 0;
}
