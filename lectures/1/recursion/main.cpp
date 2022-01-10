#include <iostream>
#include <cassert>
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

const unsigned MAXFIB = 100;

unsigned fibs[MAXFIB] = { 0 };

unsigned remember(unsigned f, unsigned n) {
    fibs[n] = f;
    return f;
}

unsigned fib(unsigned n) {
    /*
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    */
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

unsigned memofib(unsigned n) {
    if (n <= 1)
        return n;
    if (fibs[n] != 0)
        return fibs[n];
    return remember(memofib(n - 1) + memofib(n - 2), n);
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
    cout << "memofib(" << n << ") = " << memofib(n) << endl;
    cout << "fib(" << n << ") = " << fib(n) << endl;
}

bool isdigit(char c) {
    return '0' <= c && c <= '9';
}

bool isop(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double calculate(double left, char op, double right) {
    switch(op) {
        case '+' : return left + right;
        case '-' : return left - right;
        case '*' : return left * right;
        case '/' : return right == 0 ? 0 : left / right;
        default  : assert(isop(op)); return 0;
    }
}

/*
<израз> ::= <цифра>|(<израз><операция><израз>)
след завършване на функцията expr ще сочи след последния обработен символ
*/
double calculateExpression(char const*& expr) {
    if (isdigit(*expr))
        /* <цифра> */
        return *expr++ - '0';
    assert(*expr == '(');
    // да сметнем левия операнд, прескачайки отварящата скоба
    double left = calculateExpression(++expr);
    // вече сме сигурни, че сме върху операцията
    assert(isop(*expr));
    char op = *expr;
    // да сметнем десния операнд, прескачайки операцията
    double right = calculateExpression(++expr);
    assert(*expr == ')');
    // да осигурим, че expr сочи след последния обработен символ
    expr++;
    return calculate(left, op, right);
}

void testExpression() {
    const int MAX = 1000;
    char expr[MAX] = "";
    cout << "Въведете израз: ";cin.getline(expr, MAX);
    char const *p = expr;
    cout << "Резултатът е: " << calculateExpression(p) << endl;
    assert(*p == '\0');
}

int readArray(int a[]) {
  int n;
  cout << "n = ";cin >> n;
  for(int i = 0; i < n; i++) {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
  return n;
}

int sum(int a[], int n) {
    if (n == 0)
        return 0;
    // return a[n - 1] + sum(a, n - 1);
    return a[0] + sum(a + 1, n - 1);
}

bool exists(int x, int a[], int n) {
    /*
    if (n == 0)
        return false;
    if (a[n - 1] == x)
        return true;
    // n > 0 && a[n - 1] != x
    return exists(x, a, n - 1);
    */
    return n > 0 && (a[n - 1] != x || exists(x, a, n - 1));
}

void testArrays() {
    const int MAX = 100;
    int a[MAX] = {0};
    int n = readArray(a);
    cout << "Сумата на елементите е: " << sum(a, n) << endl;
}

int main() {
    // testRecursion();
    // testExpression();
    testArrays();
    return 0;
}
