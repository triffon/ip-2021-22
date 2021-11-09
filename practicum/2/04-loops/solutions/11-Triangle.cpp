// Зад 11. По въведено цяло положително число N, отпечатайте на 
// конзолата правоъгълен триъгълник със страна N от вида:
//	Вход: 3	Изход: 1		Вход: 5	Изход: 1
//				   2  3					   2  3
//				   4  5  6                 4  5  6
//									       7  8  9  10
//                                         11 12 13 14 15

#include <iostream>
using namespace std;

int main()
{
	unsigned int N;
	cin >> N;
	int current = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << current++ << " ";
		}
		cout << endl;
	}
	return 0;
}