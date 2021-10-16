#include <iostream>

using namespace std;

int main()
{
	int firstNumber;
	int secondNumber;

	cout << "Enter first number: ";
	cin >> firstNumber;
	cout << "Enter second number: ";
	cin >> secondNumber;

	//аритметични операции:
	firstNumber = firstNumber + secondNumber;
	secondNumber = firstNumber - secondNumber;
	firstNumber = firstNumber - secondNumber;

	//с помощна променлива:
	int helpingVariable = firstNumber;
	firstNumber = secondNumber;
	secondNumber = helpingVariable;
		
	//Побитовия начин ще видим в Week-3

	return 0;
}