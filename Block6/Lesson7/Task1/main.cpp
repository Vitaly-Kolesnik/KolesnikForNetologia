#include <iostream>
#include <vector>
#include <sstream>
#include <string>

template<typename T>
T square(const T& x) {
    return x * x;
}

template<typename T>
std::vector<T> square(const std::vector<T>& v) {
    std::vector<T> result;
    result.reserve(v.size());
    for (const auto& elem : v) {
        result.push_back(square(elem));
    }
    return result;
}

template<typename T>
void print_vector(const std::vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main() 
{
    int num = 4;
    std::cout << "[IN]: " << num << std::endl;
    std::cout << "[OUT]: " << square(num) << std::endl;

    std::vector<int> vec = {-1, 4, 8};
    std::cout << "[IN]: ";
    print_vector(vec);

    auto squared_vec = square(vec);
    std::cout << "[OUT]: ";
    print_vector(squared_vec);

    return 0;
}
