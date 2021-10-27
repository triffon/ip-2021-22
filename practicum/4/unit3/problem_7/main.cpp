/*
 * Задача 7
 * Създайте програма, която чете 3 реални числа, проверява дали съществува триъгълник със страни въведените числа и извежда подходящо съобщение.
 */
#include <iostream>
int main() {
	float a, b, c;
	std::cout << "Enter a, b and c: ";
	std::cin >> a >> b >> c;

	const bool canFormTriangle = a < b + c && b < a + c && c < a + b;
	if (canFormTriangle) {
		std::cout << "The given numbers form a triangle";
	} else {
		std::cout << "The given numbers do not form a triangle";
	}

	return 0;
}