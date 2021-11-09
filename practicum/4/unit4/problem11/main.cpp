#include <iostream>
using namespace std;

int main()
{
    int number, sum = 0;
    cout << "Enter number: ";
    cin >> number;

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    sum % 13 == 0 ? cout << "Yes" : cout << "No";

    return 0;
}