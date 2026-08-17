#include <iostream>
#include <vector>
#include <algorithm>

void make_unique(std::vector<int>& vec) 
{
    if (vec.empty()) return;

    std::sort(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
}

int main() 
{
    std::vector<int> data = {1, 1, 2, 5, 6, 1, 2, 4};

    std::cout << "[IN]: ";
    for (int x : data) std::cout << x << ' ';
    std::cout << std::endl;

    make_unique(data);

    std::cout << "[OUT]: ";
    for (int x : data) std::cout << x << ' ';
    std::cout << std::endl;

    return 0;
}