#include <iostream>
using namespace std;

int main()
{
    int x, counter = 1;
    double sum = 0, toAdd, numerator = 1, denominator = 1;
    cout << "Enter x";
    cin >> x;

    do {
        toAdd = numerator / denominator;
        sum += toAdd;
        numerator *= x;
        denominator *= counter;
        counter += 1;
    } while (toAdd >= 0.00001);
    cout << sum;

    return 0;
}