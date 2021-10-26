#include <iostream>

using namespace std;


int main()
{
	double a, b, c, x1, x2, determinant, realPart, imaginaryPart;
	cout << "Enter coefficient a: ";
	cin >> a;
	cout << "Enter coefficient b: ";
	cin >> b;
	cout << "Enter coefficient c: ";
	cin >> c;

	determinant = b * b - 4 * a * c;

	if (determinant > 0)
	{
		x1 = (-b + sqrt(determinant)) / (2 * a);
		x2 = (-b - sqrt(determinant)) / (2 * a);
		cout << "Roots are different" << endl;
		cout << "x1= " << x1 << endl;
		cout << "x2= " << x2 << endl;
	}
	else if (determinant == 0)
	{
		cout << "Roots are same" << endl;
		x1 = (-b + sqrt(determinant)) / (2 * a);
		cout << "x1=x2= " << x1 << endl;
	}
	else
	{
		realPart = -b / (2 * a);
		imaginaryPart = sqrt(-determinant) / (2 * a);
		cout << "Roots are different but complex" << endl;
		cout << "x1= " << realPart << "+" << imaginaryPart << "i" << endl;
		cout << "x2= " << realPart << "-" << imaginaryPart << "i" << endl;
	}

	return 0;
}