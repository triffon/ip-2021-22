#include <iostream>

int main()
{
	int min;
	std::cout << "min = ";
	std::cin >> min;

	int max;
	std::cout << "max = ";
	std::cin >> max;

	if (max < min)
	{
		int temp = min;
		min = max;
		max = temp;
	}

	int number;
	do
	{
		std::cout
			<< "Please, enter a number between ["
			<< min << ", " << max << "]: ";

		std::cin >> number;
	} while (number < min || number > max);

	std::cout << "The number is " << number << '\n';

	return 0;
}