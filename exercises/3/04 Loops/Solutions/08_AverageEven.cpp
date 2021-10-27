#include <iostream>

int main()
{
	int sumEven = 0;
	int countEven = 0;

	int number;
	std::cout << "number = ";
	std::cin >> number;

	// искаме цикълът да прекъсне, когато прочетеното число е 0
	// обратното условие се поставя в условието на цикъла
	while (number != 0)
	{
		if (number % 2 == 0)
		{
			sumEven += number;
			++countEven;
		}

		// прочитаме следващото число
		std::cout << "number = ";
		std::cin >> number;
	}

	// имаме ли изобщо четни числа сред въведените
	if (countEven != 0)
	{
		std::cout << "Average: " << static_cast<double>(sumEven) / countEven << '\n';
	}
	else
	{
		std::cout << "There are no even numbers!\n";
	}

	return 0;
}