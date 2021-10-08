//Задача шеста
#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	cin >> a;
	cout << a % 10 << (a % 100) / 10 << (a % 1000) / 100 << a / 1000;
}

