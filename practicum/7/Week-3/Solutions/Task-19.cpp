#include <iostream>

using namespace std;


int main()
{
	int number;
	cin >> number;

	if (number < 1075 || number > 8001) {
		cout << "Error\n";
	}
	else {
		if (number % 2 == 0 && number % 5 == 0) {
			cout << "Divisible by 10\n" << endl;
		}
		if (number % 6 == 0) {
			cout << "Divisible by 6\n" << endl;
		}
		if (number % 21 == 0) {
			cout << "Divisible by 21\n" << endl;
		}
	}

	return 0;
}