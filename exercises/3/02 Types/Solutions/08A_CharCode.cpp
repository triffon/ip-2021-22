#include <iostream>

int main()
{
	char c;
	std::cout << "Please, enter a symbol: ";
	std::cin >> c;

	// вариант 1, явно преобразуване до int
	std::cout << "Symbol: " << c << " Code: " << static_cast<int>(c) << '\n';
	
	int code = c;
	std::cout << "Symbol: " << c << " Code: " << code << '\n';

	bool isDigit = (c >= '0') && (c <= '9');

	std::cout << "Is digit: " << isDigit << '\n';

	return 0;
}