//Да се напише програма, която да извежда средно аритметичното на n на брой въведени числа.

#include<iostream>

int main() {

	int n;
	std::cin >> n;

	double sum = 0;
	int current = 0;

	for (int i = 0; i < n; ++i) {
		std::cin >> current;
		sum += current;
	}

	std::cout << sum/n << std::endl;
	
	return 0;
}