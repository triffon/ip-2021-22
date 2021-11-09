#include <iostream>

using namespace std;

int main()
{
    int N;
    do
    {
        cout << "Enter a whole positive number: ";
        cin >> N;
    }
    while (N < 1);

    unsigned long long n1 = 0, n2 = 1;
    unsigned long long temp;
    for (int i = 0; i < N; i++)
    {
        cout << n2 << ' ';

        temp = n2;
        n2 += n1;
        n1 = temp;
    }

    cout << endl;

    return 0;
}
