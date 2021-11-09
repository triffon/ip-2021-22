/// Прочетете от конзолата цяло число numCount ∈ [1, 127] и след това N на брой цели числа.
/// Създайте масив с елементи прочетените числа. Изведете на конзолата елементите на масива.

#include <iostream>
using namespace std;

int main()
{
    const int MAX = 128;
	int arr[MAX];
	int numCount;

	cin >> numCount;

	for(int i = 0; i < numCount; ++i)
    {
        cin >> arr[i];
    }

	for(int i = 0; i < numCount; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';

	return 0;
}
