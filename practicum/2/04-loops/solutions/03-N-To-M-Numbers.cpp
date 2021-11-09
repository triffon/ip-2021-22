// Зад 3. По въведени две цели числа N и M отпечатайте на конзолата целите числа от N до M.

#include <iostream>
using namespace std;

int main()
{
	unsigned int N, M;
	cin >> N >> M;

	for (; N <= M; ++N)
	{
		cout << N << " ";
	}

	cout << endl;

	return 0;
}