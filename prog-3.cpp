#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    std::vector<double> v(100);
    int sz = v.size();

    for(size_t i = sz-1; (i>=0 && i < sz); i--)
        v[i] = cos(i);

    std::sort(v.begin(), v.end());

    std::cout << v[0] << std::endl;
    
    return 0;
}

