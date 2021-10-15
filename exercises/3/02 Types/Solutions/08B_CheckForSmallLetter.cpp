#include <iostream>

int main()
{
	char c;
	std::cout << "Please, enter a symbol: ";
	std::cin >> c;

	// малките и главните латински букви са последователни в ASCII таблицата

	bool isSmallLetter = (c >= 'a') && (c <= 'z');
	std::cout << "Is the symbol a small letter? " << isSmallLetter << '\n';

	return 0;
}
