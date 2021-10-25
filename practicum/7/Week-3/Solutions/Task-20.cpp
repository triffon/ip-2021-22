#include <iostream>

using namespace std;


int main()
{
	char symbol;
	cin >> symbol;

	if (symbol >= 48 && symbol <= 57) {
		cout << "Symbol is a digit\n";
	}
	else if (symbol >= 65 && symbol <= 90) {
		cout << "Symbol is a capital letter\n";
	}
	else if (symbol >= 97 && symbol <= 122) {
		cout << "Symbol is a small letter\n";
	}
	else {
		cout << "Symbol is undefined in the current exercise\n";
	}
	return 0;
}