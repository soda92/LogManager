#include <boost/filesystem.hpp>
#include <iostream>

using namespace boost::filesystem;

int main()
{
    path cur = current_path();
    directory_iterator it{cur};
    while (it != directory_iterator{})
    {
        path p = *it;
        if (is_directory(p))
        {
            std::cout << "directory: " << p << '\n';
        }
        else if (is_regular_file(p))
        {
            std::cout << "file: " << p << '\n';
        }
        it++;
    }
    return 0;
}
