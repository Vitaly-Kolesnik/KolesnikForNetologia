#include <iostream>

int main(){
    std::setlocale(LC_ALL, "Russian");
    std::cout << "Введите число:\n";
    int number;
    std::cin >> number;
    std::cout << "Вы ввели число:\n" << number << "\n";
    return EXIT_SUCCESS;
}
