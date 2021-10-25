#include <iostream>

using namespace std;

int main() {
	int number;
	cin >> number;

	cout << ((((number % 10 == 7) + (number / 10 % 10 == 7) + (number / 100 % 10 == 7)) % 2) == 0);
	return 0;
}