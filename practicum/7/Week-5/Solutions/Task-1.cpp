#include <iostream>

int main()
{
	//Task 1. Да се напише програма, която проверява дали дадено число е палиндом.
	int number;
	std::cin >> number;
	int numberOfDigits = 0;
	bool isDifferent = false;
	int copyOfNumber = number;

	while (copyOfNumber > 0) {
		numberOfDigits++;
		copyOfNumber /= 10;
	}

	for (int i = 0; i < numberOfDigits; i++) {
		if ((number / (int)pow(10, i) % 10 != (number / (int)pow(10, (numberOfDigits - i - 1)) % 10))) {
			isDifferent = 1;
			break;
		}
	}
	if (isDifferent) {
		std::cout << "Number is not palindrome.\n";
	}
	else {
		std::cout << "Number is palindrome.\n";
	}

	// Друг вариант би бил да се reverse-не числото и да се сравнят първоначалното и обърнатото, ако са равни значи е палиндром.

	return 0;
}