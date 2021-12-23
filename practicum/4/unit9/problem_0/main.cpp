#include <iostream>

/*
	## Задача 0
	Създайте функция, която увеличава стойността на цяло число с 1. Параметърът на функцията да бъде от тип `int*`.
*/

void increment(int *num) {
	*num++;
}

/*
	## Задача 0.1
	Имплементирайте същата функция без да използвате указатели.
*/

void increment(int &num) {
	num++;
}

int main() {
	int n = 5;
	int *nPtr = &n;
	increment(*nPtr);
	std::cout << n << '\n';
	increment(n);
	std::cout << n << '\n';

	return 0;
}