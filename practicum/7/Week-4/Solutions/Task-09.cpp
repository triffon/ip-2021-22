/*Да се напише програма, която по въведено число n извежда всяко трето число:

от 1 до n
от 2 до n
oт 3 до n*/

#include<iostream>

int main() {

	int n;
	std::cin >> n;

	for (int i = 1; i < n; i += 3)
		std::cout << i << " ";

	std::cout << std::endl;

	for (int i = 2; i < n; i += 3)
		std::cout << i << " ";

	std::cout << std::endl;

	for (int i = 3; i < n; i += 3)
		std::cout << i << " ";

	std::cout << std::endl;

	return 0;
}