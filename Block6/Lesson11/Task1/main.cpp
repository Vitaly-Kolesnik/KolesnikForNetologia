#include <iostream>
#include <vector>
#include <string>
#include <utility>

template<typename T>
void move_vectors(std::vector<T>& source, std::vector<T>& destination) 
{
    destination = std::move(source);
}

int main() {
    std::vector<std::string> one = {"test_string1", "test_string2"};
    std::vector<std::string> two;

    std::cout << "Before move:\n";
    std::cout << "one size = " << one.size() << ", two size = " << two.size() << '\n';

    move_vectors(one, two);

    std::cout << "After move:\n";
    std::cout << "one size = " << one.size() << ", two size = " << two.size() << '\n';
    std::cout << "Contents of two:\n";
    for (const auto& s : two) {
        std::cout << s << '\n';
    }

    // one теперь пуст (размер 0)
    return 0;
}