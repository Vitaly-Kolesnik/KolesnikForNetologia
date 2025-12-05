#include <iostream>
#include <windows.h>
#include <cwctype>

const std::wstring unknownState = L"Гороскоп для вас находится в разработке. Приходите чуточку позже ;)";

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::setlocale(LC_ALL, "Russian");

	std::wcout << L"Введите информацию о себе: \n";
	std::wcout << L"Пол: ";
	std::wstring male;
	std::wcin >> male;

	for (size_t i = 0; i < male.length(); ++i) {
		male[i] = std::towupper(male[i]);
	}

	std::wcout << L"Знак зодиака: ";
	std::wstring zodiacSign;
	std::wcin >> zodiacSign;

	for (size_t i = 0; i < zodiacSign.length(); ++i) {
		zodiacSign[i] = std::towupper(zodiacSign[i]);
	}

	std::wcout << L"Возраст: ";
	int age;
	std::wcin >> age;

	if(age >= 40) 
	{
		std::wcout << unknownState;
		return EXIT_SUCCESS;
	}

	std::wcout << L"Ваше предсказание: \n";

	if(age < 40 
		&& (male == L"МУЖЧИНА" || male == L"МУЖСКОЙ" || male == L"M")
		&& (zodiacSign == L"РАК" || zodiacSign == L"СКОРПИОН" || zodiacSign == L"РЫБЫ")) 
	{
		std::wcout << L"Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным. \n";
	} 
	else if ((age >= 15 && age <= 30)
		&& (male == L"ЖЕНЩИНА" || male == L"ЖЕНСКИЙ" || male == L"Ж")
		&& (zodiacSign == L"ТЕЛЕЦ" || zodiacSign == L"ДЕВА" || zodiacSign == L"КОЗЕРОГ"))
	{
		std::wcout << L"Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок. \n"
			L"Будет не только весело, но и интересно : найдётся дело, которое увлечёт всех.";
	} 
	else 
	{
		std::wcout << unknownState;
	}

	return EXIT_SUCCESS;
}