/*
 * Задача 4
 * Създайте програма, която чете цяло четирицифрено число и извежда сумата от цифрите му.
 */
#include <iostream>

int main() {
	int a;
	std::cout << "Enter an integer with 4 digits: ";
	std::cin >> a;

	const int firstDigit = a / 1000;
	const int secondDigit = a / 100 % 10;
	const int thirdDigit = a / 10 % 10;
	const int fourthDigit = a % 10;

	const int sumOfDigits = firstDigit + secondDigit + thirdDigit + fourthDigit;
	std::cout << "The sum of its digits is " << sumOfDigits;
	return 0;
}