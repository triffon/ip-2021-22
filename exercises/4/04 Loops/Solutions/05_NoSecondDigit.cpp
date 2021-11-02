#include <iostream>
#include <iomanip>

int main()
{
	int m;
	std::cout << "m = ";
	std::cin >> m;

	int n;
	std::cout << "n = ";
	std::cin >> n;

	// вариант 1. 
	// проверка на всяко от числата в интервала дали е трицифрено
	for (int number = m; number <= n; ++number)
	{
		if (number >= 100 && number < 1000)
		{
			int hundreds = number / 100;
			int ones = number % 10;

			int numberWithoutTens = hundreds * 10 + ones;

			if (number % numberWithoutTens == 0)
			{
				std::cout << number << '\t';
			}
		}
	}

	std::cout << '\n';

	// вариант 2.
	// проверка на интервала, преди да бъде обходен
	// ако горната граница е по-малка от 100 или долната граница е над 999,
	// няма трицифрени числа в интервала
	if (n < 100 || m > 900)
	{
		std::cout << "[" << m << ", " << n << "] does not have a three-digit numbers!\n";
	}
	else
	{
		// да се намери сечението на двата интервала...
		// std::max(m, 100)
		int left = (m < 100) ? 100 : m;
		// std::min(n, 999)
		int right = (n < 999) ? n : 999;

		for (int number = left; number <= right; ++number)
		{
			int hundreds = number / 100;
			int ones = number % 10;

			int numberWithoutTens = hundreds * 10 + ones;

			if (number % numberWithoutTens == 0)
			{
				std::cout << number << '\t';
			}	
		}
	}

	return 0;
}