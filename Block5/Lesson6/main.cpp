#include <iostream>
#include <string>

int simple_string_hash(std::string s) 
{
    int hash = 0;
    
    for (char c : s) 
	{
        hash += static_cast<int>(c);
    }
    
    return hash;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    
    std::string input;
    do 
	{
        std::cout << "Введите строку: ";
        std::getline(std::cin, input);
        std::cout << "Наивный хэш строки " << input << " = " << simple_string_hash(input) << std::endl;

    } while (input != "exit");

    return 0;
}
