#include <iostream>

using namespace std;

int main()
{
    int num, pow;
    long long res = 1;
    cin >> num >> pow;

    if (pow < 0)
    {
        cout << "Wrong input!" << '\n';
        return 1;
    }

    for (int i = 0; i < pow; i++)
        res *= num;

    cout << res << '\n';

    return 0;
}
