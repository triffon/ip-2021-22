//Да се напише програма, която извежда броя на единици и нули в бинарното представяне на въведено число n.
#include<iostream>

int main() {
	int n;
	std::cin >> n;

	int zeros = 0;
	int ones = 0;

	while (n) {
		if (!(n % 2))
			zeros++;
		else
			ones++;

		n /= 2;
	}

	std::cout << "has " << zeros << " zeros and " << ones << " ones.\n";

	return 0;
}