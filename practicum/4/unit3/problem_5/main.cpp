/*
 * Задача 5
 * Създайте програма, която чете реалните числа a и b и решава линейното уравнение ax=b
 */
#include <iostream>
int main() {
	int a, b;
	std::cout << "Enter a and b: ";
	std::cin >> a >> b;

	/*
	  За линейното уравнение от типа ax=b има 3 възможни случая
	   - a == 0 && b == 0 => Всяко х е решение
	   - a == 0 && b != 0 => Няма решение
	   - a != 0           => Има точно едно решение x = b/a;
	*/

	if (a == 0) {
		if (b == 0) {
			std::cout << "Every x is a root";
		}
		else {
			std::cout << "There are no roots";
		}
	}
	else {
		std::cout << "The equation has exactly one solution " << b / a;
	}

	return 0;
}