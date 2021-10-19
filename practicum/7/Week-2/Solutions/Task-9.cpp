#include <iostream>

using namespace std;

int main()
{
	char symbol;
	cin >> symbol;

	cout << (((int)symbol >= 65 && (int)symbol <= 90) || ((int)symbol >= 97 && (int)symbol <= 122)) << endl;

	//The next code is for 9.1
	cout << '+' * '/' << endl; //Every symbol has an integer representation :)

	return 0;
}