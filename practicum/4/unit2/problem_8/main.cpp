/*
 * Създайте програма, която чете 3 реални числа, представляващи страните на един триъгълник. Програмата трябва да изведе
 * периметъра и лицето на триъгълника.
 * Напомняне: Лицето на един тригълник със страни a, b и c се смята най-лесно с формулата на Херон:
 * S=sqrt(p*(p-a)*(p-b)*(p-c)) където p=(a+b+c)/2
 * Допуснете, че въведените 3 числа формират съществуващ триъгълник
 */
#include <cmath> // iostream includes cmath in some implementations, but it is recommended to include it explicitly
#include <iostream>
int main() {
	float a, b, c;

	std::cout << "Enter the sides of the triangle: ";
	std::cin >> a >> b >> c;

	const float perimeter = a + b + c;

	const float p = perimeter / 2;
	const float area = sqrt(p*(p - a)*(p - b)*(p - c));

	std::cout << "The perimeter is " << perimeter << "\n";
	std::cout << "The area is " << area << "\n";
	return 0;
}