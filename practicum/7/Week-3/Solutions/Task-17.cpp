#include <iostream>

using namespace std;


int main()
{
	int year;
	cout << "Enter year: ";
	cin >> year;

	cout << boolalpha << "Is " << year << " leap year: " << (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) << endl;

	//Above we used the easy way, now lets use IF statements
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
		cout << year << " is leap year\n";
	}
	else {
		cout << year << " is not a leap year\n";
	}

	return 0;
}