#include "Utils.hpp"

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

    fs::create_directory("Logs");
}