#include <iostream>
using namespace std;


int main() {

	//task 2

	// a^2 + b^2 = c^2 - прав ъгъл
	// а^2 + b^2 > c^2 - остроъгълен
	// a^2 + b^2 < c^2 - тъпоъгълен

	//a + c > b, a + b > c, b + c > a
	// a > 0, b > 0, c > 0

	//int a, b, c;

	//cin >> a >> b >> c;

	//if (a + c > b && a + b > c && b + c > a && a > 0 && b > 0 && c > 0)
	//{
	//	if (a * a + b * b == c * c)
	//	{
	//		cout << "Правоъгълен" << endl;
	//	}
	//	else if (a * a + b * b > c* c)
	//	{
	//		cout << "Остроъгълен" << endl;
	//	}
	//	else
	//	{
	//		cout << "Тъпоъгълен" << endl;
	//	}
	//}
	//else
	//{
	//	cout << "Invalid triangle";
	//}

	//task 5:

	//int a, b, c;
	//double D;
	//double x1, x2;

	//cin >> a >> b >> c;

	//if (a == 0 && b == 0)
	//{
	//	cout << "No solution" << endl;
	//}
	//else if (a == 0)
	//{
	//	x1 = (double)-c / (double)b;
	//	cout << "x = " << x1 << endl;
	//}
	//else
	//{
	//	D = b * b - 4 * a * c;

	//	if (D < 0)
	//	{
	//		cout << "No solution";
	//	}
	//	else if (D == 0)
	//	{
	//		x1 = -b / (2 * a);
	//		cout << "x = " << x1 << endl;
	//	}
	//	else {
	//		x1 = (-b + sqrt(D)) / (2 * a);
	//		x2 = (-b - sqrt(D)) / (2 * a);
	//		cout << "x1 = " << x1 << " x2 = " << x2 << endl;
	//	}

	//}


	//task 7:

	//int month;

	//cin >> month;

	//switch (month)
	//{
	//	case 1: case 2: case 3:
	//		cout << "Winter"; break;
	//	case 4: case 5: case 6:
	//		cout << "Spring"; break;
	//	case 7: case 8: case 9:
	//		cout << "Summer"; break;
	//	case 10: case 11: case 12:
	//		cout << "Autumn"; break;
	//	default:
	//		cout << "There is no such month"; break;
	//}

	char ch, ch2;
	cin >> ch;




	int number;
	number = ch - '0';



	cout << number << endl;
	cout << number + 10 << endl;
	cout << ch + 10 << endl;

	//"245624" -> number;



	return 0;
}