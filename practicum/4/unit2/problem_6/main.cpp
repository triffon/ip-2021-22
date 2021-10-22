/*
 * Задача 6
 * Създайте програма, която чете цяло число с поне 3 цифри и извежда третата му цифра (отдясно-наляво).
 */
#include <iostream>

int main() {
	int a;
	std::cout << "Enter an integer with at least 3 digits: ";
	std::cin >> a;

	std::cout << "Its third digit (from right to left) is " << a / 100 % 10;
	return 0;
}