#include <iostream>

int main()
{
	double x;
	std::cout << "x = ";
	std::cin >> x;

	double sum = 1;
	for (int n = 2; n <= 11; ++n)
	{
		sum = sum * x + n;
	}

	std::cout << "sum = " << sum << '\n';
	return 0;
}