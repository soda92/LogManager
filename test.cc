#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string str = "0123";
    cout << str.substr(0, 2) << "\n";
    cout << str.substr(2, string::npos) << "\n";
    return 0;
}