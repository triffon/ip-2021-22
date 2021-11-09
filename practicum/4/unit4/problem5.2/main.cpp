#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    int max = (a > b) ? a : b;
    cout << 111111111;
    do
    {
        if (max % a == 0 && max % b == 0)
        {
            cout << "LCM = " << max;
            break;
        }
        else {
            ++max;
        }
    } while (true);
    return 0;
}