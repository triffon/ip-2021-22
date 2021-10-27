/*
 * Задача 9
 * Създайте програма, която чете цяло число year и проверява дали year е високосна година и извежда подходящо съобщение.
 *   Подсказка: Номерът на високосна година се дели на 4 и не се дели на 100, или пък се дели на 400.
 */
#include <iostream>
int main() {
	int year;
	std::cin >> year;
	const bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	std::cout << "The year " << year << (isLeapYear ? " is a leap year" : " is not a leap year");

	return 0;
}