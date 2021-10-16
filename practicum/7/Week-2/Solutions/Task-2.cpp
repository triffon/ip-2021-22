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

	cout << "Сума: " << firstNumber + secondNumber << endl;
	cout << "Разлика: " << abs(firstNumber - secondNumber) << endl;
	cout << "Произведение: " << firstNumber * secondNumber << endl;
	cout << "Частното на X с Y, закръглено отдолу: " << floor((double)firstNumber / secondNumber) << endl;
	cout << "Частното на X с Y, закръглено отгоре: " << ceil((double)firstNumber / secondNumber) << endl;
	cout << "Y повдигнато на степен корен квадратен от X: " << pow(firstNumber, sqrt(secondNumber)) << endl;
	cout << "Остатъка при деление на първото с второто число: " << firstNumber % secondNumber << endl;

	return 0;
}