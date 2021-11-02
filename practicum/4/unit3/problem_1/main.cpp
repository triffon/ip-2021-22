/*
 * Задача 1
 * Създайте програма, която чете 2 цели числа и извежда по-голямото измежду тях.
 */
#include <iostream>
int main() {
	int a, b;
	std::cout << "Enter 2 integers: ";
	std::cin >> a >> b;

	int max = a;
	if (b > a) {
		max = b;
	}
	std::cout << "The maximum of these two numbers is " << max;

	// По-кратък начин, използвайки тернарния оператор:
	//std::cout << "The maximum of these two is " << (a > b ? a : b);

	return 0;
}