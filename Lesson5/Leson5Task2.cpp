#include <iostream>
#include <cstdlib>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, "Russian");
	
    const int size = { 10 };
    int arrayNumbers[size] = { 1, 90, 50, 30, 5, 0, 8, 10, 11, 9 };
    int max = arrayNumbers[0];
    int min = arrayNumbers[0];

    std::cout << "Maccив: ";

    for (int i : arrayNumbers)
    {
        std::cout << i << " ";

        if(i < min)
        {
            min = i;
        }
        else if(i > max)
        {
            max = i;
        }
    }

    std::cout << "\nМинимальный элемент: " << min;
    std::cout << "\nМаксимальный элемент: " << max;
    return EXIT_SUCCESS;
}