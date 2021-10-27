#include <iostream>

int main()
{
	int m;
	std::cout << "m = ";
	std::cin >> m;

	int n;
	std::cout << "n = ";
	std::cin >> n;

	for (int number = m; number <= n; ++number)
	{
		int sum = 1;
		int limit = number / 2;

		for (int div = 2; div <= limit; ++div)
		{
			if (number % div == 0)
			{
				sum += div;
			}
		}

		if (number == sum)
			std::cout << number << " is perfect!\n";
		else
			std::cout << number << " is not perfect!\n";
	}

	return 0;
}