#include <iostream>

int main()
{
	int x, n;
	std::cout << "Enter x: ";
	std::cin >> x;
	std::cout << "Enter n: ";
	std::cin >> n;
	int p = 1, fact = 1, sum;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 1; j <= i; j++) //pow and fact
		{
			p *= x;
			fact *= j;
		}
		sum += p / fact;
	}
	std::cout << "Sum of series: " << sum;
	return 0;
}