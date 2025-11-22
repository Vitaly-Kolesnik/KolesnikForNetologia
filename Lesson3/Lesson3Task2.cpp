#include <iostream>

int main()
{
	std::cout << "Hello" << "\n";
	std::cout << "Give me 3 integers numbers. Enter them using enter.";
	std::cout << "\n";

	int firstNumber; 
	std::cin >> firstNumber;
	std::cout << "\n";

	int secondNumber;
	std::cin >> secondNumber;
	std::cout << "\n";

	int thirdNumber;
	std::cin >> thirdNumber;
	std::cout << "\n";

	std::cout << "Result: ";

	(firstNumber >= secondNumber && firstNumber >= thirdNumber)
		? (secondNumber >= thirdNumber
			? (std::cout << firstNumber << " " << secondNumber << " " << thirdNumber)
			: (std::cout << firstNumber << " " << thirdNumber << " " << secondNumber))
		: (secondNumber >= firstNumber && secondNumber >= thirdNumber)
		? (firstNumber >= thirdNumber
			? (std::cout << secondNumber << " " << firstNumber << " " << thirdNumber)
			: (std::cout << secondNumber << " " << thirdNumber << " " << firstNumber))
		: (firstNumber >= secondNumber
			? (std::cout << thirdNumber << " " << firstNumber << " " << secondNumber)
			: (std::cout << thirdNumber << " " << secondNumber << " " << firstNumber));

	return EXIT_SUCCESS;
}
