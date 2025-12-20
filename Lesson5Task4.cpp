#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, "Russian");

    const int arraySize = 10;
    int arrayNumbers[arraySize] = { 0, 3, 5, 6, 2, 8, 7, 9, 15, 7 };

    std::cout << "Массив до сортировки:\t";
    for (int number : arrayNumbers) std::cout << number << " ";
    std::cout << "\n";
    for (int i = 0; i < arraySize - 1; ++i)
    {
        for (int f = 1; f < arraySize - i; ++f)
        {
            if (arrayNumbers[f] > arrayNumbers[f - 1])
            {
                std::swap(arrayNumbers[f], arrayNumbers[f - 1]);
            }
        }
    }

    std::cout << "Массив после сортировки:\t";
    for (int number : arrayNumbers) std::cout << number << " ";
    std::cout << "\n";
    return EXIT_SUCCESS;
}