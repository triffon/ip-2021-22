#include <iostream>

int main()
{
	int start;
	std::cout << "start = ";
	std::cin >> start;

	int end;
	std::cout << "end = ";
	std::cin >> end;

	if (start > end)
	{
		int temp = start;
		start = end;
		end = temp;
	}

	int step;
	std::cout << "step = ";
	std::cin >> step;

	if (step < 0)
		step = -step;

	int sum = 0;
	int count = 0;

	for (int number = start; number <= end; number += step)
	{
		sum += number;
		++count;
	}

	std::cout << "sum = " << sum << '\n';
	
	double average = static_cast<double>(sum) / count;
	std::cout << "Average: " << average << '\n';

	return 0;
}