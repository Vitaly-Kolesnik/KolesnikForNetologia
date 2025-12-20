#include <iostream>

int main()
{
    const int size = 10;
    const std::string  comma = ", ";
    int arrayNumbers[size] = { 1, 2, 3, 4, 5, 6, 8, 10, 11, 9 };
    
    for(int i = 0; i < 10; ++i)
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << arrayNumbers[i];
            if (i < size - 1)
            {
                std::cout << comma;
            }
        }
    }

    return EXIT_SUCCESS;
}