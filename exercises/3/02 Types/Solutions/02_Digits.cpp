#include <iostream>

int main()
{
	// деклариране на променливата, в която ще бъде съхранено трицифреното число
	int number;
	std::cout << "Please, enter a three-digit number: ";
	std::cin >> number;

	int hundreds = number / 100;
	int tens = (number / 10) % 10;
	int ones = number % 10;

	std::cout 
		<< "The digits of the number " << number << " are:\n" 
		<< "(hundreds) " << hundreds << '\n'
		<< "(tens) " << tens << '\n'
		<< "(Ones) " << ones << '\n';

	int sumOfDigits = hundreds + tens + ones;
	std::cout << "The sum of the digits in " << number << " is " << sumOfDigits << '\n';

	int reverseNumber = ones * 100 + tens * 10 + hundreds;
	std::cout << "The reverse number of " << number << " is " << reverseNumber << '\n';

	return 0;
}