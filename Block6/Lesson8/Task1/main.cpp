#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() 
{
    std::string text;
    std::getline(std::cin, text);

    std::map<char, int> freq;
    for (char ch : text) 
	{
        ++freq[ch];
    }

    std::vector<std::pair<char, int>> freq_vec(freq.begin(), freq.end());
    std::sort(freq_vec.begin(), freq_vec.end(),
        [](const auto& a, const auto& b) 
		{
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });

    for (const auto& [ch, count] : freq_vec) {
        std::cout << ch << ": " << count << '\n';
    }

    return 0;
}