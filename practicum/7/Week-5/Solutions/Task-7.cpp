#include <iostream>

int main()
{
	/*Task 7. Дадени са целите числа `a` и `b` (0 <= а <= b). Да се напише програма, която извежда на екрана всички цели числа от 
	интервала [a, b], цифрите на които образуват монотонно растяща редица.*/
	unsigned int a, b;
	do {
		std::cout << "a = ";
		std::cin >> a;
		std::cout << "b = ";
		std::cin >> b;
	} while (a < 0 || a > b);

	for (int i = a; i <= b; i++)
	{
		int lastDigit = i % 10;
		int remainingNumber = i / 10;
		while (remainingNumber != 0 && lastDigit >= remainingNumber % 10) {
			lastDigit = remainingNumber % 10;
			remainingNumber /= 10;
		}
		if (remainingNumber == 0) {
			std::cout << i << ' ';
		}
	}
	return 0;
}