//Задача четвърта
#include <iostream>
using namespace std;

int main()
{
	//Първи начин
	int a = 0, b = 0, temp = 0;
	cin >> a >> b;
	temp = a;
	a = b;
	b = temp;

	//Втори начин
	int x = 0, y = 0;
	cin >> x >> y;
	x = x + y; //x += y
	y = x - y;
	x = x - y;

	//Трети начин
	int f = 0, s = 0;
	cin >> f >> s;
	f = f * s;
	s = f / s;
	s = f / s;
}