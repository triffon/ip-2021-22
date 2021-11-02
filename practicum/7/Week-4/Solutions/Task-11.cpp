//Да се напише програма, която извежда всички делители на n.

#include<iostream>

int main() {
	unsigned n;
	std::cin >> n;

	for (int i = 0; i <= n; ++i)
		if (n % i == 0)
			std::cout << i << " ";

	return 0;
}