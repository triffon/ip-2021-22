#include<iostream>

using namespace std;

int main() {
	int number = 0;
	std::cin >> number;
	std::cout << 3 * (number / 3) * (number / 3 + 1) / 2;
}