#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, "Russian");

    const int digitBase = 10;

    int inputNumber = 0;
    int sum = 0;

    while(true)
    {
        std::cout << "Введите целое число: \n";
        std::cin >> inputNumber;
        int temp = std::abs(inputNumber);
        while(temp != 0)
        {
            sum += temp % digitBase;
            temp /= digitBase;
        }

        std::cout << "Сумма цифр:" << sum << "\n";
    }

    return EXIT_SUCCESS;
}