#include <iostream>

// <iostream> include-ва <cmath> и вече съществува функция със сигнатура pow(double, int).
double pow2(double x, int n) {
	if (n < 0) {
		return 1 / pow2(x, -n);
	}
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return x;
	}
	return x * pow2(x, n - 1);
}

int main() {
	double x;
	int n;
	std::cin >> x >> n;
	std::cout << pow2(x, n);
	return 0;
}