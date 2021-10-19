#include <iostream>

using namespace std;

int main()
{
	int number;
	cin >> number;

	int firstDigit = number / 1000 % 10;
	int secondDigit = number / 100 % 10;
	int thirdDigit = number / 10 % 10;
	int lastDigit = number % 10;

	cout << lastDigit << '#' << thirdDigit << '#' << secondDigit << '#' << firstDigit << endl;

	return 0;
}