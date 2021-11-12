// Зад 10. По въведено цяло число N, изведете броя на делителите му.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	unsigned int count = 2;
	double sqrtN = sqrt(N);

	for (int i = 2; i < sqrtN; i++)
	{
		count += (N % i == 0) ? 2 : 0;
	}

	if ((int)sqrtN * (int)sqrtN == N)
		count++;

	cout << count << endl;

	return 0;
}