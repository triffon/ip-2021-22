//Да се напише програма, която проверява дали дадено число n е просто.
#include<iostream>

int main() {
	unsigned n;
	std::cin >> n;

	bool is_prime = 1;

	if (n == 0 || n == 1)
		is_prime = 0;

	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			is_prime = 0;
			break;
		}
	}
	
	std::cout << (is_prime ? "yes" : "no");

	return 0;
}