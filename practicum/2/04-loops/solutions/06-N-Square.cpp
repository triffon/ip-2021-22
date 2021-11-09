// Зад 6. По въведено цяло положително число N, отпечатайте на конзолата
// “квадрат” с дължина на страната N.
// Вход: 3	Изход : ###	Вход : 5	Изход : #####
//					# #						#   #
//					###						#   #
//											#   #
//											#####

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == 0 || i == N - 1)
			{
				cout << '#';
			}
			else
			{
				if (j == 0 || j == N - 1)
				{
					cout << '#';
				}
				else
				{
					cout << ' ';
				}
			}
		}
		cout << endl;
	}

	return 0;
}