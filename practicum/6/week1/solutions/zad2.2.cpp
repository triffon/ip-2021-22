#include<iostream>

using namespace std;

int main() {
	int number = 0;
	std::cin >> number;
	std::cout << ((number % 3 == 0) ^ (number % 5 == 0));
}