// «ад 5. ѕо подадени две цели числа N и M намерете и изведете сумата на числата от N до M.

#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int sum = (M - N + 1) * (M + N) / 2;
	
	cout << sum << endl;
	return 0;
}
