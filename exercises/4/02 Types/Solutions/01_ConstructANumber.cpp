#include <iostream>

int main()
{
	// деклариране на променлива, в която ще бъде съхранена цифрата на стотиците
	int hundreds;
	std::cout << "Hundreds: ";
	std::cin >> hundreds;

	// променлива, в която ще бъде съхранена цифрата на десетиците
	int tens;
	std::cout << "Tens: ";
	std::cin >> tens;

	// променлива, в която ще бъде съхранена цифрата на единиците
	int ones;
	std::cout << "Ones: ";
	std::cin >> ones;

	int number = hundreds * 100 + tens * 10 + ones;
	std::cout << "number = " << number << '\n';

	return 0;
}