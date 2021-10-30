#include <iostream>

int main()
{
	unsigned number;
	std::cout << "number = ";
	std::cin >> number;

	unsigned originalNumber = number;

	unsigned maxDigit = 0;
	unsigned countDigits = 0;

	if (number == 0)
	{
		countDigits = 1;
	}
	else
	{
		while (number > 0)
		{
			unsigned currentDigit = number % 10;
			if (maxDigit < currentDigit)
			{
				maxDigit = currentDigit;
			}

			++countDigits;

			number = number / 10;
			//number /= 10;
		}
	}
	
	std::cout << "The number of digits in " << originalNumber << " is " << countDigits << '\n';
	std::cout << "The max digit in " << originalNumber << " is " << maxDigit << '\n';

	return 0;
}