/// Напишете програма, която намира най-големия елемент в масив.
#include <iostream>
using namespace std;

int main()
{
	const int MAX = 100;
	int arr[MAX];
	int numCount;

	cin >> numCount;
	cin >> arr[0];

	int maxNum = arr[0];

	for(int i = 1; i < numCount; i++)
    {
        cin >> arr[i];
        if(maxNum < arr[i])
        {
            maxNum = arr[i];
        }
    }

    cout << maxNum << '\n';

	return 0;
}
