/*
 * Задача 2
 * Създайте програма, която чете 3 цели числа и ги извежда в намаляващ ред.
 */
#include <iostream>
int main() {
	int a, b, c;
	std::cout << "Enter 3 integers: ";
	std::cin >> a >> b >> c;

	// Има 6 (3!) пермутации на 3 числа a,b,c: abc, acb, bac, bca, cab, cba
	if (a >= b & b >= c) {
		std::cout << a << " " << b << " " << c;
	}
	else if (a >= c && c >= b) {
		std::cout << a << " " << c << " " << b;
	}
	else if (b >= a && a >= c) {
		std::cout << b << " " << a << " " << c;
	}
	else if (b >= c && c >= a) {
		std::cout << b << " " << c << " " << a;
	}
	else if (c >= a && a >= b) {
		std::cout << c << " " << a << " " << b;
	}
	else { // cba е единствената останала възможна пермутация
		std::cout << c << " " << b << " " << a;
	}

	return 0;
}