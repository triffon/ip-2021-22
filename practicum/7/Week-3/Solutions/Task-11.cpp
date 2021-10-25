#include <iostream>

using namespace std;

int main()
{
	char firstSymbol, secondSymbol, thirdSymbol;
	cout << "Enter first symbol: ";
	cin >> firstSymbol;
	cout << "Enter second symbol: ";
	cin >> secondSymbol;
	cout << "Enter third symbol: ";
	cin >> thirdSymbol;

	int firstSymbolToDigit = firstSymbol - '0';
	int secondSymbolToDigit = secondSymbol - '0';
	int thirdSymbolToDigit = thirdSymbol - '0';

	int result = firstSymbolToDigit * 100 + secondSymbolToDigit * 10 + thirdSymbolToDigit;
	cout << result << endl;

	return 0;
}