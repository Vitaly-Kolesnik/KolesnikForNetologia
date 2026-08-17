#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
    int n;
	
    if (!(std::cin >> n)) 
	{
        return 0;
    }

    std::vector<int> numbers;
    numbers.reserve(n);

    for (int i = 0; i < n; ++i) 
	{
        int x;
        std::cin >> x;
        numbers.push_back(x);
    }

    std::sort(numbers.begin(), numbers.end());
    auto last = std::unique(numbers.begin(), numbers.end());
    numbers.erase(last, numbers.end());
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) 
	{
        std::cout << *it << '\n';
    }

    return 0;
}
