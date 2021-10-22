#include <iostream>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    double perimeter = 2 * a + 2 * b;
    double area = a * b;

    cout << "P = " << perimeter << endl;
    cout << "S = " << area << endl;

    return 0;
}