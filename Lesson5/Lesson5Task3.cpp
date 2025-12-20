#include <iostream>
#include <tuple>
#include <cstdlib>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, "Russian");
 
    const int rows = 3;
    const int columns = 6;
    int arrayNumbers[rows][columns] =
    {
        {1, 90, 50, 30, 5, 0},
        {5, 25, 21, 12, 3, 78},
        {66, 99, 33, 89,51, 60}
    };

    auto indexMaxElement = std::make_tuple(0, 0);
    auto indexMinElement = std::make_tuple(0, 0);
    int max = arrayNumbers[0][0];
    int min = arrayNumbers[0][0];
    std::cout << "Maccив:\n";
    for (int i = 0; i < rows; ++i)
    {
        for(int f = 0; f < columns; ++f)
        {
            std::cout << arrayNumbers[i][f] << "\t";
            if (arrayNumbers[i][f] < min)
            {
                min = arrayNumbers[i][f];
                indexMinElement = { i, f };
            }
            else if (arrayNumbers[i][f] > max)
            {
                max = arrayNumbers[i][f];
                indexMaxElement = { i, f };
            }
        }

        std::cout << "\n";
    }

    std::cout << "»ндекс минимального элемента: "
        << std::get<0>(indexMinElement) << " " << std::get<1>(indexMinElement);

    std::cout << "\n»ндекс максимального элемента: "
        << std::get<0>(indexMaxElement) << " " << std::get<1>(indexMaxElement);
    return EXIT_SUCCESS;
}