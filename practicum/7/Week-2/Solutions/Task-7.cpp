#include <iostream>

using namespace std;

int main()
{
	const double PI = 3.141592653589793238463;
	double radius, area, perimeter, diameter;
	cout << "Enter radius: ";
	cin >> radius;

	area = radius * radius * PI;
	perimeter = 2 * PI * radius;
	diameter = 2 * radius;

	cout << "Area: " << area << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << "Diameter: " << diameter << endl;

	return 0;
}