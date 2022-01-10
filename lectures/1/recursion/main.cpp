#include <iostream>
using namespace std;

unsigned fact(unsigned n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

unsigned gcd(unsigned a, unsigned b) {
    if (a == 0 && b == 0) {
        cerr << "gcd: Некоректни стойности на a и b!" << endl;
        return 0;
    }
    if (a == 0)
        return b;
    if (b == 0 || a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    // b > a
    return gcd(a, b - a);
}

double power(double x, int n) {
    if (n == 0)
        return 1;
    if (n > 0)
        return x * power(x, n - 1);
    // n < 0
    return 1 / power(x, -n);
}

void testRecursion() {
    unsigned n;
    cout << "n = ";cin >> n;
    cout << n << "! = " << fact(n) << endl;
    unsigned x;
    cout << "x = ";cin >> x;
    cout << "gcd(" << n << ',' << x << ") = " << gcd(n, x) << endl;
    cout << x << "^" << n << " = " << power(x, n) << endl;
    cout << x << "^(-" << n << ") = " << power(x, -(int)n) << endl;
}

int main() {
    testRecursion();
    return 0;
}
