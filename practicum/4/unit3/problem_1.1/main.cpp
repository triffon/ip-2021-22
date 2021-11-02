/*
 * Задача 1*
 * Създайте програма, която чете 3 цели числа и извежда най-голямото измежду тях.
 */
#include <iostream>
int main() {
	int a, b, c;
	std::cout << "Enter 3 integers: ";
	std::cin >> a >> b >> c;

	int max = a;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	std::cout << max;

	// Алтернативен вариант 1)
	//if (a >= b && a >= c) {
	//	std::cout << a;
	//} else if (b >= a && b >= c) {
	//	std::cout << b;
	//} else {
	//	std::cout << c;
	//}

	// Алтернативен вариант 2 - тернарен оператор (не много добре четим))
	//std::cout << (
	//	a >= b ? 
	//	(a >= c ? a : c) :
	//	(b >= c ? b : c)
	//);

	return 0;
}