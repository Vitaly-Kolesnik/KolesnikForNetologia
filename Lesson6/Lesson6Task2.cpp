#include <iostream>
#include <cstdlib>
#include <windows.h>

int calculatePower(int value, int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= value;
    }
    return result;
}

void printResult(int result, int value, int power)
{
    std::cout << value << " в степени " << power << " = " << result << std::endl;
}

int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::setlocale(LC_ALL, "Russian");

    int value = { 5 };
    int power = { 2 };
    int result = { calculatePower(value, power) };

    printResult(result, value, power);

    value = { 3 };
    power = { 3 };
    result = { calculatePower(value, power) };

    printResult(result, value, power);

    value = { 4 };
    power = { 4 };
    result = { calculatePower(value, power) };

    printResult(result, value, power);

    return 0;
}