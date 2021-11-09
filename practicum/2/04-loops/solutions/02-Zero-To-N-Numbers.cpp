// Зад 2. По въведено цяло положително число N, отпечатайте на 
//			конзолата целите числа от 0 до N.

#include <iostream>
using namespace std;

int main()
{
	unsigned int N;
	cin >> N;

	for (int i = 0; i <= N; ++i)
	{
		cout << i << " ";
	}

	cout << endl;

	return 0;
}
