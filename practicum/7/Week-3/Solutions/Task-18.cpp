#include <iostream>

using namespace std;

bool isLeapYear(int year) {
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int main()
{
	int month;
	cout << "Enter number between 1 - 12: ";
	cin >> month;
	int year;
	cout << "Enter year: ";
	cin >> year;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		cout << "31 days\n";
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		cout << "30 days\n";
	}
	else if (month == 2)
	{
		if (isLeapYear(year)) {
			cout << "29 days\n";
		}
		else {
			cout << "28 days\n";
		}
	}
	else
	{
		cout << "Invalid input...Please enter month number between 1-12\n";
	}

	return 0;
}