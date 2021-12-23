#include <iostream>
#include <cmath>

// Създайте функция, която приема като аргумент указател(или референция) към цяло число 
// и променя стойността на числото да бъде първото просто число, което е по - голямо.

bool isPrime(int n) {
	if (n == 0 || n == 1) return false;

	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void setToNextPrime(int &n) {
	for (int i = n + 1;; i++) {
		if (isPrime(i)) {
			n = i;
			return;
		}
	}
}

int main() {
	int n;
	std::cin >> n;
	setToNextPrime(n);
	std::cout << n << '\n';
	return 0;
}