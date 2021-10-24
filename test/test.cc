#include <iostream>
#include <string>
#include <fmt/core.h>
using namespace std;

int main()
{
    std::string str = "0123";
    cout << str.substr(0, 2) << "\n";
    cout << str.substr(2, string::npos) << "\n";
    fmt::print("{:03}\n",1);
    return 0;
}
