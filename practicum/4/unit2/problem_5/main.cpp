/*
 * Задача 5
 * Създайте програма, която чете трицифрено число и извежда числото със същите цифри, но в обратен ред.
 */
#include <iostream>

int main() {
	int a;
	std::cout << "Enter an integer with 3 digits: ";
	std::cin >> a;

	const int firstDigit = a / 100;
	const int secondDigit = a / 10 % 10;
	const int thirdDigit = a % 10;

	int reverse = thirdDigit * 100 + secondDigit * 10 + firstDigit;
	std::cout << "The reverse number is " << reverse;
	
	return 0;
}