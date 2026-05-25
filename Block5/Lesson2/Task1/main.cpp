#include <iostream>

long long fibonacci(int n) 
{
    if (n == 0)
	{ 
		return 0;
	}
	
    if (n == 1) 
	{
		return 1;
	}

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() 
{
    std::cout << "Введите номер числа Фибоначчи (n): ";
    int n;
    
    if (std::cin >> n && n >= 0) 
	{
        long long result = fibonacci(n);
        std::cout << n << "-е число Фибоначчи равно: " << result << std::endl;
    } 
	else 
	{
        std::cerr << "Пожалуйста, введите корректное неотрицательное число." << std::endl;
    }

    return 0;
}