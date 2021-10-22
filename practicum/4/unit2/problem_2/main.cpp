/*
 * Задача 2
 * Създайте програма, която чете 2 цели числа от конзолата: k и m.
 * Програмата трябва да изведе колко сантиметра се съдържат в k километра и m метра.
 */
#include <iostream>

int main() {
	int k, m;
	std::cout << "Enter k: ";
	std::cin >> k;
	std::cout << "Enter m: ";
	std::cin >> m;

	const int CMS_IN_KILOMETER = 100000;
	const int CMS_IN_METER = 100;

	const float cm = k * CMS_IN_KILOMETER + m * CMS_IN_METER;

	std::cout << "There are " << cm << " centimeters in " << k << " kilometers and " << m << " meters\n";

	return 0;
}