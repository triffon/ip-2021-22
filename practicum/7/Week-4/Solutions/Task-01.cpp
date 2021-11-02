//Да се напише програма, която по въведено число n, извежда цифрите му на екрана.

#include<iostream>

int main() {
	int n;
	std::cin >> n;

	int reverse = 0;

	while (n) { //като обърнем числото ще може да изведем цифрите му в правилния ред
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}

	while (reverse) {
		std::cout << reverse % 10 << " ";
		reverse /= 10;
	}

	std::cout << std::endl;

	return 0;
}