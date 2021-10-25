#include <iostream>

using namespace std;

/**
 * По въведен знак (+,-,*,/) и две числа, да извърши операцията.
 */
int main()
{
    char chSign;
    float num1, num2;

    cout << "Enter expression in the format <operation> <num> <num>: ";
    cin >> chSign >> num1 >> num2;

    switch ( chSign )
    {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '/':
            cout << num1 / num2;
            break;
        default:
            cout << "Unsupported operation!";
            break;
    }

    return 0;
}
