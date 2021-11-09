#include <iostream>
using namespace std;

int main()
{
    int number, sum = 0;
    do {
        cin >> number;
        sum += number;
    } while (number != 0);
    cout << sum;

    return 0;
}