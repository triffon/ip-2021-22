#include <iostream>

using namespace std;

int main()
{

    int limit, divisor1, divisor2, divisor3;
    cin >> limit >> divisor1 >> divisor2 >> divisor3;

    if (limit < 0)
    {
        cout << "Limit must be positive!" << '\n';
        return 1;
    }

    if (divisor1 == 0 || divisor2 == 0 || divisor3 == 0)
    {
        cout << "Can not devide by zero!" << '\n';
        return 2;
    }


    for (int i = 0; i <= limit; i++)
        if ((i % divisor1 == 0) && (i % divisor2 == 0) && (i % divisor3 == 0))
            cout << i << ' ';

    cout << '\n';

    return 0;
}
