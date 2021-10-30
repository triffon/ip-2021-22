#include <iostream>
#include <iomanip>

int main()
{
	int number;
	std::cout << "number = ";
	std::cin >> number;

	if (number == 2 || number == 3 || number == 5 || number == 7)
		std::cout << "The number is prime!\n";
	else
		std::cout << "The number is not prime!\n";

	switch (number)
	{
		case 2: 
		case 3:
		case 5:
		case 7: 
			std::cout << "The number is prime!\n"; 
			break;
		default:
			std::cout << "The number is not prime!\n";
			break;
	}

	return 0;
}