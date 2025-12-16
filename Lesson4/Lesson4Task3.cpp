#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, "Russian");

    int inputNumber = 0;
    
    const std::string multiplicationSign = " x " ;
    const std::string equalSign = " = ";
    
    std::cout << "¬ведите целое число: \n";
    std::cin >> inputNumber;

    for(int i=1; i<=10; ++i)
    {
        std::cout << inputNumber << multiplicationSign << i << equalSign << (inputNumber * i) << "\n";
    }

    return EXIT_SUCCESS;
}