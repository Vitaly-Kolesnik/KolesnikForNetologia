#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, "Russian");

    int sumNumbers = 0;
    int inputNumber = 0;
    while (std::cout << "¬ведите целое число или число '0', чтобы закончить: \n", std::cin >> inputNumber, inputNumber != 0)
        sumNumbers += inputNumber;

    std::cout << "—умма: " << sumNumbers << "\n";

    return EXIT_SUCCESS;
}

