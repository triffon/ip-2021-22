#include <iostream>

using namespace std;

int main()
{
	/*double firstSide, height;
	cout << "Enter side of triangle: ";
	cin >> firstSide;
	cout << "Enter height of triangle: ";
	cin >> height;

	double area;
	area = (firstSide * height) / 2;
	cout << "Area is: " << area << endl;*/

	double firstSide, secondSide, thirdSide, area, halfPerimeter;
	cout << "Enter first side: ";
	cin >> firstSide;
	cout << "Enter second side: ";
	cin >> secondSide;
	cout << "Enter third side: ";
	cin >> thirdSide;
	halfPerimeter = (firstSide + secondSide + thirdSide) / 2;
	area = sqrt(halfPerimeter * (halfPerimeter - firstSide) * (halfPerimeter - secondSide) * (halfPerimeter - thirdSide));
	cout << "Area is: " << area << endl;

	return 0;
}