#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Enter number: ";
    cin >> number;

    while (number > 0) {
        cout << number % 10 << endl;
        number /= 10;
    }
}