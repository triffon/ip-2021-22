#include <iostream>
// Създайте функция, която по дадени числител и знаменател на дроб я съкращава.

int gcd(int a, int b) {
	while (b) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

void simplify(int &numer, int &denom) {
	const int commonDivisor = gcd(numer, denom);
	numer /= commonDivisor;
	denom /= commonDivisor;
}

int main() {
	int numer, denom;
	std::cin >> numer >> denom;
	// Допускаме, че denom!=0.
	simplify(numer, denom);
	std::cout << numer;
	if (denom != 1) {
		std::cout << "/" << denom;
	}
	return 0;
}