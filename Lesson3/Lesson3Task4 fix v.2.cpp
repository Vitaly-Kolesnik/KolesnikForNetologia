#include <iostream>
#include <windows.h>
#include <locale>
#include <cstdlib>


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::setlocale(LC_ALL, "Russian");

	int a, b;
	std::cout << "Введите целое число: ";
	std::cin >> a;
	std::cout << "Введите целое число: ";
	std::cin >> b;
	if (a <= -100 || a >= 100 || b <= -100 || b >= 100) {
		std::cout << "Ошибка! Одно из чисел вне диапазона!" << std::endl;
		return EXIT_SUCCESS;
	}
	int temp = a;
	if (temp < 0) {
		std::cout << "минус ";
		temp = -temp;
	}
	int tens = temp / 10;
	int ones = temp % 10;
	switch (tens) {
	case 9: std::cout << "девяносто"; break;
	case 8: std::cout << "восемьдесят"; break;
	case 7: std::cout << "семьдесят"; break;
	case 6: std::cout << "шестьдесят"; break;
	case 5: std::cout << "пятьдесят"; break;
	case 4: std::cout << "сорок"; break;
	case 3: std::cout << "тридцать"; break;
	case 2: std::cout << "двадцать"; break;
	case 1:
		switch (ones) {
		case 0: std::cout << "десять"; break;
		case 1: std::cout << "одиннадцать"; break;
		case 2: std::cout << "двенадцать"; break;
		case 3: std::cout << "тринадцать"; break;
		case 4: std::cout << "четырнадцать"; break;
		case 5: std::cout << "пятнадцать"; break;
		case 6: std::cout << "шестнадцать"; break;
		case 7: std::cout << "семнадцать"; break;
		case 8: std::cout << "восемнадцать"; break;
		case 9: std::cout << "девятнадцать"; break;
		}
		break;
	}
	if (tens > 1 && ones != 0) std::cout << " ";
	if (tens != 1) {
		switch (ones) {
		case 1: std::cout << "один"; break;
		case 2: std::cout << "два"; break;
		case 3: std::cout << "три"; break;
		case 4: std::cout << "четыре"; break;
		case 5: std::cout << "пять"; break;
		case 6: std::cout << "шесть"; break;
		case 7: std::cout << "семь"; break;
		case 8: std::cout << "восемь"; break;
		case 9: std::cout << "девять"; break;
		case 0: if (tens == 0) std::cout << "ноль"; break;
		}
	}
	if (a < b) std::cout << " меньше чем ";
	else if (a > b) std::cout << " больше чем ";
	else std::cout << " равно ";
	temp = b;
	if (temp < 0) {
		std::cout << "минус ";
		temp = -temp;
	}
	tens = temp / 10;
	ones = temp % 10;
	switch (tens) {
	case 9: std::cout << "девяносто"; break;
	case 8: std::cout << "восемьдесят"; break;
	case 7: std::cout << "семьдесят"; break;
	case 6: std::cout << "шестьдесят"; break;
	case 5: std::cout << "пятьдесят"; break;
	case 4: std::cout << "сорок"; break;
	case 3: std::cout << "тридцать"; break;
	case 2: std::cout << "двадцать"; break;
	case 1:
		switch (ones) {
		case 0: std::cout << "десять"; break;
		case 1: std::cout << "одиннадцать"; break;
		case 2: std::cout << "двенадцать"; break;
		case 3: std::cout << "тринадцать"; break;
		case 4: std::cout << "четырнадцать"; break;
		case 5: std::cout << "пятнадцать"; break;
		case 6: std::cout << "шестнадцать"; break;
		case 7: std::cout << "семнадцать"; break;
		case 8: std::cout << "восемнадцать"; break;
		case 9: std::cout << "девятнадцать"; break;
		}
		break;
	}
	if (tens > 1 && ones != 0) std::cout << " ";
	if (tens != 1) {
		switch (ones) {
		case 1: std::cout << "один"; break;
		case 2: std::cout << "два"; break;
		case 3: std::cout << "три"; break;
		case 4: std::cout << "четыре"; break;
		case 5: std::cout << "пять"; break;
		case 6: std::cout << "шесть"; break;
		case 7: std::cout << "семь"; break;
		case 8: std::cout << "восемь"; break;
		case 9: std::cout << "девять"; break;
		case 0: if (tens == 0) std::cout << "ноль"; break;
		}
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
