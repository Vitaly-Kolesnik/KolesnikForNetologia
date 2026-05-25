#include <iostream>
#include <vector>

long long fibonacci_memo(int n, std::vector<long long>& memo) 
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo[n] != -1) 
	{
        return memo[n];
    }

    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
    return memo[n];
}

int main() {
    std::cout << "Введите номер числа Фибоначчи (n): ";
    int n;

    if (std::cin >> n && n >= 0) 
	{
        std::vector<long long> memo(n + 1, -1);
        
        long long result = fibonacci_memo(n, memo);
        std::cout << n << "-е число Фибоначчи равно: " << result << std::endl;
    } 
	else 
	{
        std::cerr << "Пожалуйста, введите корректное неотрицательное число." << std::endl;
    }

    return 0;
}