#include <iostream>
using namespace std;

int main()
{
    long i, n;
    cout << "n:"; cin >> n;
    cout << "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }

    return 0;
}