#include <iostream>

int main()
{
	/* Task 6. Едно положително цяло число се нарича * *съвършено**, ако е равно на сумата от своите делители(без самото число).
	Например 6 е съвършено (6 = 1 + 2 + 3), а 1 НЕ е съвършено. Да се напише програма, която намира всички съвършени числа ненадминаващи 
	дадено положително цяло число `n`.*/

	int n;
	do {
		std::cout << "Enter positive integer: ";
		std::cin >> n;
	} while (n < 0);

	for (int i = 2; i <= n; i++)
	{
		int sumOfDivisors = 1;
		for (int j = 2; j <= i / 2; j++)  //sqrt(n)
		{
			if (i % j == 0) sumOfDivisors += j;
		}
		if (sumOfDivisors == i) std::cout << i << " ";
	}
	return 0;
}