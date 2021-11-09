#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    int min = a < b ? a : b;
    for (int i = min; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            cout << i;
            break;
        }
    }
return 0;
}
