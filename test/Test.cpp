#include "Utils.hpp"
#include <iostream>
#include <fmt/core.h>

int main()
{
    auto dates = get_dates(7);
    for (auto i : dates)
    {
        std::cout << i << "\n";
    }
    fmt::print("{}\n", get_log_path());
    return 0;
}
