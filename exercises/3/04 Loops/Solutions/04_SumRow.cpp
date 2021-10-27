#include <iostream>
#include <iomanip>

int main()
{
	int n;
	std::cout << "n = ";
	std::cin >> n;

	// вариант 1. 
	// Проверка за четна и нечетна позиция.
	double sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i % 2 == 0)
		{
			sum = sum - 1.0 / i;
		}
		else
		{
			sum = sum + 1.0 / i;
		}
	}

	std::cout << "sum = " << std::setiosflags(std::ios::fixed) << std::setprecision(3) << sum << '\n';

	// вариант 2.
	// знакът на събираемото се променя алтернативно (1, -1/2, 1/3...),
	// може да се използва помощна променлива, чиито знак да се променя на всяка стъпка
	sum = 0;

	int signOne = 1;
	for (int i = 1; i <= n; ++i)
	{
		sum = sum + signOne * 1.0 / i;
		// обръщаме знака
		signOne = -signOne;
	}

	std::cout << "sum = " << std::setiosflags(std::ios::fixed) << std::setprecision(3) << sum << '\n';

	return 0;
}