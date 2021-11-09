#include <iostream>

int main()
{
	// Task 2. Да се изведе следната "фигура" на конзолата:
	// std::endl прави същото като '\n'

	for (int i = 7; i >= 1; i--) {
		for (int j = 1; j <= 7 - i; j++) {
			std::cout << " " << " ";
		}
		for (int k = 1; k <= i; k++) {
			std::cout << k << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}