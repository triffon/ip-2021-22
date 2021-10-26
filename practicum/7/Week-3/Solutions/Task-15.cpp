#include <iostream>

using namespace std;


int main()
{
	int firstNumber, secondNumber;
	cout << "Enter first number: ";
	cin >> firstNumber;
	cout << "Enter second number: ";
	cin >> secondNumber;

	cout << boolalpha << (firstNumber == 5 || secondNumber == 5 || firstNumber + secondNumber == 5 || abs(firstNumber - secondNumber) == 5);


	return 0;
}