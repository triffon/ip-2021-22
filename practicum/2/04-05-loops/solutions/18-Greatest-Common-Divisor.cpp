#include <iostream>

using namespace std;

int main()
{
    int num1, num2, remainder;
    do
    {
        cout << "Enter two positive whole numbers: ";
        cin >> num1 >> num2;
    }
    while (num1 < 1 || num2 < 1);

    if (num1 < num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    do
    {
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }
    while (remainder != 0);

    cout << num1;

    return 0;
}
