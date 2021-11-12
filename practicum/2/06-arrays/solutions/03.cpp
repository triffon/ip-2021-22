/// Напишете програма, която намира втория по
/// големина елемент в масив.
#include <iostream>
using namespace std;

int main()
{
	const int MAX = 100;
	int arr[MAX];
	int numCount;

	cin >> numCount;
	cin >> arr[0];

	int maxNumIndex = 0;
	int maxNum = arr[0];

	for(int i = 1; i < numCount; i++)
    {
        cin >> arr[i];
        if(maxNum < arr[i])
        {
            maxNum = arr[i];
            maxNumIndex = i;
        }
    }

    int secondMaxNum = arr[0];
    if(maxNumIndex == 0)
    {
        secondMaxNum = arr[1];
    }

    for(int i = 0; i < numCount; i++)
    {
        if(i == maxNumIndex)
        {
            ++i;
        }
        else
        {
            if(secondMaxNum < arr[i])
            {
                secondMaxNum = arr[i];
            }
        }
    }

    cout << secondMaxNum << '\n';

	return 0;
}
