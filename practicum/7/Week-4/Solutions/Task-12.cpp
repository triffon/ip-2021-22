//Да се напише програма, която извежда бинарния вид на числото n.

#include <iostream>

int main() {

	int n;
	std::cin >> n;

	int bin = 0;

	while (n) {
		bin = bin * 10 + n % 2;
		n /= 2;
	}

	while (bin) {
		std::cout << bin % 10;
		bin /= 10;
	}

	return 0;
}