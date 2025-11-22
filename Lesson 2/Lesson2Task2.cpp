#include <iostream>
#include <windows.h>

int main(){
    std::setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::wcout << L"Введите слово:\n";
    std::wstring word;
    std::wcin >> word;
    std::wcout << L"Вы ввели слово:\n" << word << "\n";
    return EXIT_SUCCESS;
}
