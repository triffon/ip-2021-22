#include <iostream>

int main()
{
	char c;
	std::cout << "Please, enter a small letter: ";
	std::cin >> c;

	// c - 'a' намира на колко стъпки се намира символът c от малката буква 'a'
	// главната буква, съответстваща на c, се намира на също толкова стъпки от 'А'

	char capitalLetter = c - 'a' + 'A';
	std::cout << "The corresponding capital letter is: " << capitalLetter << '\n';

	return 0;
}