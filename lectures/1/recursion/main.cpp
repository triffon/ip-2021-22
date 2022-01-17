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

unsigned readArray(int a[]) {
  unsigned n;
  cout << "n = ";cin >> n;
  for(int i = 0; i < n; i++) {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
  return n;
}

// извеждане на масив a от n цели числа
int* printArray(int* a, int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return a;
}

int sum(int a[], unsigned n) {
    if (n == 0)
        return 0;
    // return a[n - 1] + sum(a, n - 1);
    return a[0] + sum(a + 1, n - 1);
}

bool exists(int x, int a[], unsigned n) {
    /*
    if (n == 0)
        return false;
    if (a[n - 1] == x)
        return true;
    // n > 0 && a[n - 1] != x
    return exists(x, a, n - 1);
    */
    // if (X) return false; Y    <-> return !X && Y
    // if (U) return true; V     <-> return U || V
    return n > 0 && (a[n - 1] == x || exists(x, a, n - 1));
}

bool isSorted(int a[], unsigned n) {
    return n <= 1 || a[n - 2] <= a[n - 1] && isSorted(a, n - 1);

    if (n <= 1)
        return true;
    // !!! n > 0, n >= 1
    // n > 1, n >= 2
    return a[n - 2] <= a[n - 1] && isSorted(a, n - 1);
}

bool areDifferent(int a[], unsigned n) {
    return n <= 1 || !exists(a[n - 1], a, n - 1) && areDifferent(a, n - 1);
    //if (n == 0)
    if (n <= 1)
        return true;
    // !!! return a[n - 2] != a[n - 1] && areDifferent(a, n - 1);
    /*
    if (n == 2 && a[0] == a[1])
        return false;
    */ 
    if (exists(a[n - 1], a, n - 1))
        return false;
    // n > 1 && !exists(a[n-1], a, n - 1)
    return areDifferent(a, n - 1);
}

/*
    Функцията разделя масива на две части
    В лявата част са елементи < pivot
    Във дясната част са елементи >= pivot
    Връща индекса на последния елемент в лявата част
*/
int split(int a[], unsigned n, int pivot) {
    int i = 0, j = n - 1;
    while (i != j)
        if (a[i] < pivot)
            // a[i] вече е в лявата част на масива, където трябва да бъде
            i++;
        else
            // a[i] трябва да се премести в дясната част!
            if (a[j] >= pivot)
                // a[j] вече е в дясната част на масива, където трябва да бъде
                j--;
            else
                // a[j] трябва да се премести в лявата част!
                // разменяме ги!
                swap(a[i], a[j]);
    // i == j
    // какво знаем за a[i]?
    // нищо, трябва да проверим в коя част на масива трябва да бъде
    if (a[i] < pivot)
        // a[i] трябва да се причисли към лявата част на масива
        // т.е. i е индексът на последния елемент в лявата част на масива
        return i;
    // a[i] трябва да се причисли към дясната част на масива
    // възможно е да се получи -1, ако лявата част се окаже празна
    return i - 1;
}

void quicksort(int a[], unsigned n) {
    if (n > 1) {
        int pivot = a[0];
        int pivotIndex = split(a + 1, n - 1, pivot) + 1;
        // +1 защото искаме да броим от началото на нашия, оригинален масив
        swap(a[0], a[pivotIndex]);
        // a[0] вече е на окончателната си позиция
        // рекурсивно сортираме лявата част
        quicksort(a, pivotIndex);
        // рекурсивно сортираме дясната част (пропускаме оста!)
        quicksort(a + pivotIndex + 1, n - 1 - pivotIndex);
    }
}

void testArrays() {
    const int MAX = 100;
    int a[MAX] = {0};
    unsigned n = readArray(a);
    cout << "Сумата на елементите е: " << sum(a, n) << endl;
    int x;
    cout << "x = "; cin >> x;
    cout << "Елементът " << x;
    if (!exists(x, a, n))
        cout << " НЕ";
    cout << " се среща в масива." << endl;
    cout << "Масивът";
    if (!isSorted(a, n))
        cout << " НЕ";
    cout << " е сортиран." << endl;
    cout << "Масивът";
    if (!areDifferent(a, n))
        cout << " НЕ";
    cout << " се състои от различни елементи." << endl;
    quicksort(a, n);
    printArray(a, n);
}


int main() {
    // testRecursion();
    // testExpression();
    testArrays();
    return 0;
}
