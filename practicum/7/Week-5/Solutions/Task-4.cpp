#include <iostream>

bool isPrime(int number) {
	if (number <= 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	/*
	Task 4. Две числа се наричат **сдвоени прости** числа, ако са прости и ако `a + 4 = b`. Напишете  програма, която извежда на екрана всички
	- двойки сдвоени нечени
	числа в даден интервал [m, n], където `m` и `n` се въвеждат от конзолата.
	*/

	int firstNumber, secondNumber;
	std::cin >> firstNumber >> secondNumber;
	for (int i = firstNumber; i <= secondNumber; i++)
	{
		for (int j = i + 1; j <= secondNumber; j++)
		{
			if (i + 4 == j && i % 2 != 0 && j % 2 != 0 && isPrime(i) && isPrime(j)) {
				std::cout << i << " " << j << '\t';
			}
		}
	}

	return 0;
}