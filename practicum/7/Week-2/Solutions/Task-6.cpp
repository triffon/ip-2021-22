#include <iostream>

using namespace std;

int main()
{
	double centimeters, meters, kilometers;
	cout << "Enter centimeters: ";
	cin >> centimeters;

	meters = centimeters / 100;
	kilometers = centimeters / 100000;
	
	cout << "In meters: " << meters << endl;
	cout << "In kilometers: " << kilometers << endl;

	return 0;
}