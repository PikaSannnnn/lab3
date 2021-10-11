#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void print_cases(const std::string& name)
{
    int len = name.size();
    char up[len + 1];
    char lo[len + 1];

    for(size_t i = 0; i < name.size(); i++)
    {
        up[i] = std::toupper(name[i]);
        lo[i] = std::tolower(name[i]);
    }

    up[len] = '\0';
    lo[len] = '\0';

    std::cout << lo << " " << up << std::endl;
}

int main()
{
    print_cases("Elizabeth");
    print_cases("John");
    print_cases("Frank");
    print_cases("Fred");

    return 0;
}

