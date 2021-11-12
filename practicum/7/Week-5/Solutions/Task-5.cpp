#include <iostream>

int main()
{
	//Task 5. Да се напише програма, която изтрива нечетните цифри на дадено **неотрицателно** цяло число. (без масиви)
	unsigned int number;  //usingned int -> int ,който е винаги положителен
	int zerosCount = 0;
	unsigned int reversedNumber = 0;
	do {
		std::cout << "Enter positive integer: ";
		std::cin >> number;
	} while (number < 0);

	while (number != 0 && number % 10 == 0) {
		zerosCount++;
		number /= 10;
	}

	while (number != 0) {
		if (number % 10 % 2 == 0) {
			reversedNumber = reversedNumber * 10 + number % 10;
		}
		number /= 10;
	}

	if (reversedNumber != 0) {
		while (reversedNumber != 0) {
			std::cout << reversedNumber % 10;
			reversedNumber /= 10;
		}
		for (; zerosCount > 0; zerosCount--)
		{
			std::cout << '0';
		}
	}
	else {
		std::cout << 0;
	}

	return 0;
}