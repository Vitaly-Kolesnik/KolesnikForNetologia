#include <iostream>
#include <string>
#include <cmath>

long long real_string_hash(const std::string& s, long long p, long long n) 
{
    long long hash = 0;
    long long p_power = 1;

    for (char c : s) 
	{
        long long char_code = static_cast<long long>(c);
        hash = (hash + char_code * p_power) % n;
        p_power = (p_power * p) % n;
    }

    return hash;
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    long long p;
    long long n;

    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cin.ignore(); 
    std::string input;

    do 
	{
        std::cout << "Введите строку: ";
        std::getline(std::cin, input);

        long long hash_value = real_string_hash(input, p, n);
        std::cout << "Хэш строки " << input << " = " << hash_value << std::endl;

    } while (input != "exit");

    return 0;
}