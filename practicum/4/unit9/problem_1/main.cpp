#include <iostream>
/*
	Задача 1
	Създайте функция, която разменя стойностите на 2 цели числа.
*/

void swap(int &a, int &b) {
	int x = a;
	a = b;
	b = x;
}

int main() {
	int a = 5, b = 3;
	swap(a, b);
	std::cout << a << " " << b;

	return 0;
}