#include <iostream>

bool containsDigit(int n, int k) {
	if (n == 0) return false;
	if (n%10 == k) return true;
	return containsDigit(n / 10, k);
}

int main() {
	int n, k;
	std::cin >> n >> k;
	std::cout << std::boolalpha << containsDigit(n, k);
	return 0;
}