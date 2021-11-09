#include <iostream>

using namespace std;

int main()
{
    long long num;
    do
    {
        cout << "Enter a whole non-negative number: ";
        cin >> num;
    }
    while (num < 0);

    unsigned numLength = 0;
    int temp = num;
    while (temp)
    {
        ++numLength;
        temp /= 10;
    }

    long long rev = 0;
    for (int i = 0; i < numLength / 2; i++)
    {
        rev *= 10;
        rev += num % 10;
        num /= 10;
    }

    if (numLength % 2 != 0)
        num /= 10;

    if (num == rev)
        cout << "Palindrom" << '\n';
    else
        cout << "Not palindrom" << '\n';

    cout << '\n';

    return 0;
}
