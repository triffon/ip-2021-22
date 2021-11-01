//Да се напише програма, която по въведено в бинарен вид число n, пресмята и го извежда в десетичен вид.
#include<iostream>

int main() {
	
	unsigned binary;
	std::cin >> binary;

	int decimal = 0;
	int power_of_two = 1;

	while (binary) {
		decimal = decimal + binary % 10 * power_of_two;
		power_of_two *= 2;
		binary /= 10;
	}

	std::cout << decimal;

	return 0;
}