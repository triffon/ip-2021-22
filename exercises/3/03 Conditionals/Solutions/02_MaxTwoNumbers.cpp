#include <iostream>

int main()
{
	int x;
	std::cout << "x = ";
	std::cin >> x;

	int y;
	std::cout << "y = ";
	std::cin >> y;

	int max;

	// вариант 1. 
	// конструиране на аритметичен израз
	max = (x >= y) * x + (x < y) * y;
	std::cout << "1. max = " << max << '\n';

	// вариан 2.
	// с използване на if
	if (x >= y)
	{
		max = x;
	}
	else
	{
		max = y;
	}
	std::cout << "2. max = " << max << '\n';

	// вариант 3.
	max = x;
	if (max < y)
	{
		max = y;
	}
	std::cout << "3. max = " << max << '\n';

	// вариант 4.
	// с използване на тернарен оператор
	max = (x >= y) ? x : y;
	std::cout << "4. max = " << max << '\n';

	return 0;
}