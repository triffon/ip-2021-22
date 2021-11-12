//Да се напише програма, която по въведени числа x <= 10 и y <= 10 извежда на екрана:
//-правоъгълник
//-рамка


#include<iostream>

int main() {

	int x, y;
	std::cin >> x >> y;

	//правоъгълник
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j){
			std::cout << "* ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//рамка
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
				std::cout << "* ";
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}

	return 0;
}