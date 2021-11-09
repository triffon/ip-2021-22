#include <iostream>

using namespace std;

int main()
{
    int num;
    do
    {
        cout << "Enter a non-negative number: ";
        cin >> num;
    }
    while (num < 0);

    unsigned res = 1;
    for (int i = 2; i <= num; i++)
        res *= i;

    cout << res << endl;

    return 0;
}
