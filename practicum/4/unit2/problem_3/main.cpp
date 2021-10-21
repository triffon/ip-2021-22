/*
 * Задача 3
 * Създайте програма, която чете 2 цели числа, разменя стойностите им и ги извежда в конзолата.
 */
#include <iostream>

int main() {
	int a, b;
	std::cout << "Enter a and b: ";
	std::cin >> a >> b;

	int x = a;
	a = b;
	b = x;

	std::cout << "After swapping, a is " << a << " and b is " << b;
	return 0;
}