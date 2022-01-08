#include <iostream>

int digitsSum(int n) {
	if (n < 0) {
		return digitsSum(-n);
	}
	if (n >= 0 && n <= 9) {
		return n;
	}
	return n % 10 + digitsSum(n / 10);
}

int main() {
	int n;
	std::cin >> n;
	std::cout << digitsSum(n);
	return 0;
}