#include "Utils.hpp"
#include <iostream>

int main()
{
    auto dates = get_dates(7);
    for (auto i : dates)
    {
        std::cout << i << "\n";
    }
    return 0;
}
