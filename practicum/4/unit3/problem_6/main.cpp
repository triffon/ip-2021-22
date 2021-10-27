/*
 * Задача 6
 * Създайте програма, която чете реалните числа a, b и c и решава линейното уравнение ax^2+bx+c=0
 */
#include <cmath>
#include <iostream>
int main() {
	float a, b, c;
	std::cout << "Enter a, b and c: ";
	std::cin >> a >> b >> c;

	/*
	  За квадратно уравнение от типа ax^2+bx+c=0 имаме следните възможни случаи:
	   - a == 0 => Уравението е линейно с коефициенти b и c
	   За линейно уравенение от типа bx+c=0 имаме следните възможни случаи:
	    * b == 0 && c == 0 => Всяко х е решение
	    * b == 0 && c != 0 => Няма решение
	    * b != 0           => Има точно 1 решение x = -c/b;
	   - a != 0 => Уравнението наистина е квадратно. Намираме D. Това отваря 3 възможни случая:
	    * D  < 0 => Уравнението няма реални корени.
		* D  > 0 => Уравнението има 2 корена
		* D == 0 => Уравнението има 1 корен
	*/

	if (a == 0.0f) { // Linear equation
		if (b == 0.0f) {
			if (c == 0.0f) {
				std::cout << "Every x is a root";
			} else {
				std::cout << "There are no roots";
			}
		} else {
			std::cout << "The equation has exactly one solution " << -c / b;
		}
	} else {
		const float D = b * b - 4 * a*c;
		if (D < 0) {
			std::cout << "There are no roots";
		} else if (D > 0) {
			const float x1 = (-b + sqrt(D)) / (2 * a);
			const float x2 = (-b - sqrt(D)) / (2 * a);
			std::cout << "The roots are " << x1 << " and " << x2;
		} else { // D == 0
			const float x = -b / (2 * a);
			std::cout << "The root is " << x;
		}
	}

	return 0;
}