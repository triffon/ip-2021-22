#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0;
    do
    {
        cout << "Enter a whole non-negative number: ";
        cin >> num;
    }
    while (num < 0);

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    cout << sum;

    return 0;
}
