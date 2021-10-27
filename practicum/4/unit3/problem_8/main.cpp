/*
 * Задача 8
 * Създайте програма, която чете 3 реални числа и проверява дали съществува триъгълник със страни въведените числа. 
 * Ако съществува такъв триъгълник, програмата трябва да изведе дали триъгълникът, който сформират е:
 *  - Равностранен, равнобедрен или разностранен
 *  - Остроъгълен, правоъгълен или тъпоъгълен
 */
#include <cmath>
#include <iostream>
int main() {
	const double PI = 3.1415926535;

	float a, b, c;
	std::cout << "Enter a, b and c: ";
	std::cin >> a >> b >> c;

	const bool canFormTriangle = a < b + c && b < a + c && c < a + b;
	if (canFormTriangle) {
		std::cout << "The given numbers form a triangle";
		if (a == b && a == c) {
			std::cout << " which is equilateral";
		} else if(a == b || a == c || b == c) {
			std::cout << " which is isosceles";
		} else {
			std::cout << " which is scalene";
		}

		const double alpha = acos((b*b + c * c - a * a) / (2 * b*c)) * 180.0 / PI;
		const double beta = acos((a*a + c * c - b * b) / (2 * a*c)) * 180.0 / PI;
		const double gamma = 180.0 - alpha - beta;

		if (alpha < 90.0 && beta < 90.0 && gamma < 90.0) {
			std::cout << " and acute";
		} else if (alpha > 90.0 || beta > 90.0 || gamma > 90.0) {
			std::cout << " and obtuse";
		} else {
			std::cout << " and right";
		}
	} else {
		std::cout << "The given numbers do not form a triangle";
	}

	return 0;
}