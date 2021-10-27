/*
 * Задача 3
 * Създайте програма, която чете цяло число x и извежда y, където
 * y = 0, ако x <= 5
 * y = x * x, ако x > 5
 */
#include <iostream>
int main() {
	int x;
	std::cout << "Enter x: ";
	std::cin >> x;

	if (x <= 5) {
		std::cout << "y=" << 0;
	}
	else {
		std::cout << "y=" << x * x;
	}

	// Тернарният оператор е много подходящ за подобни математически функции
	//std::cout << "y=" << (x <= 5 ? 0 : x * x);

	return 0;
}