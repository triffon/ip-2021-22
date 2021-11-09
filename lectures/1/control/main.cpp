#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

int main1() {
    cout << "Hello, world!\n" << "It's me!" << endl;
    2 + 3;
    exp(sin(sqrt(15)));
    int x = 2;
    x = 5;
    x = 3.8;
    x = true;
    x = 2 <= 3;
    x = 'A';
    // !!! x = cout;
    // !!! x = (int)cout;
    cout << x << endl;
    cout << ++++x << endl;
    cout << x++ << endl;
    cout << x << endl;
    // !!! x++ = 3;
    // !!! int x = 5;
    {
        int x = 5;;;;;;;;;;;;;;;;;;;;;;;;;;
        ++x;;;;;
        cout << x << endl;
    };;;;;
    cout << ((((((x)))))) << endl;
    return 0;
}

int main2() {
    int a, b, c;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;

    // !!! if ((c > b) > a)
    /*
    if (c > b && b > a) // || a > b && b > c)
       cout << "Образуват растяща редица" << endl;
    else
       cout << "НЕ образуват растяща редица" << endl;
    */
    //c > b && b > a ? cout << "Образуват растяща редица" << endl : cout << "НЕ образуват растяща редица" << endl;
    cout << (c > b && b > a ? "О" :"НЕ о") << "бразуват растяща редица" << endl;

    cout << "Най-малкото число е ";
    /*
    if (a <= b && a <= c)
        cout << a;
    else if (b <= a && b <= c)
        cout << b;
    else
        cout << c;
    cout << endl;
    */

    cout << (a <= b && a <= c ? a : b <= c && b <= a ? b : c) << endl;
    // cout << min(a, min(b, c)) << endl;

/*
    if (a <= b)
        if (a <= c)
            cout << a;
        else
            // c < a <= b
            cout << c;
    else
        // a > b
        if (b >= c)
            cout << c;
        else
        // a > b && b < c
            cout << b;
*/
    return 0;
}

int main3() {
    int x;
    cout << "x = ";cin >> x;
    switch (x) {
        case 1 : x++;
        // !!! case y - 2 : x++;
        case 2 : x += 2;
        default : x += 5;
    }
    cout << x << endl;
    return 0;
}

int main4() {
    int a, b;
    /* bcout << "a = ";cin >> a;
    cout << "b = ";cin >> b; */
    char op;
    /*
    cout << "op = "; cin >> op;*/
    cout << "Въведете израз: ";
    cin >> a >> op >> b;
    cout << a << " " << op << " " << b << " = ";
    switch (op) {
        // !!! case "+" : cout << a + b; break;
        case '+' : cout << a + b; break;
        case '-' : cout << a - b; break;
        case '.' :
        case '*' : cout << a * b; break;
        case '/' : // !!! cout << (b == 0 ? '!' : a / b); break;
                   // !!! cout << (b == 0 ? "!"" : a / b); break;
                   assert(b != 0);
                   cout << a / b; break;
                   // if (b == 0) cout << '!'; else cout << a / b; break;
        case '%' : // !!! cout << a % b; break;
                   if (b == 0) cout << '!'; else cout << a % b; break;
        default :  cout << '?';
    }
    cout << endl;

    return 0;
}

int main5() {
    int n;
    cout << "n = "; cin >> n;
    assert(n >= 0);
    long long f = 1;
    for(int i = 1 ; /* cout << "i = " << i << endl, */ i <= n ; i++)
        f *= i;
    // i > n
    cout << n << "! = " << f << endl;
    return 0;
}

int main6() {
   int n;
   cout << "n = "; cin >> n;
   double x;
   cout << "x = "; cin >> x;
   long double s = 1, y = 1;
   // y == a0 == 1
   // s == a0 == 1
   for(int i = 1; i <= n; i++) {
       // s == сумата на всички от a0 до a(i-1) включително
       // y == a(i-1)

       /*
      long f = 1;
      for(int j = 1 ; j <= i ; j++)
        f *= j;

      double y = pow(x, i) / f;
      */
      (y *= x) /= i;
      // y == ai
      s += y;

      // s == сумата на всички до a0 до ai включително
   }
   cout << "exp(x) = " << exp(x) << endl;
   cout << "s      = " << s << endl;
   return 0;
}

int main7() {
   unsigned n; // == unsigned int
   cout << "n = "; cin >> n;
   unsigned count = 0;
   for(int i = 1; i <= n; i++) {
       int xi = n * n * n + 5 * i * i * n - 8 * i;
       if (xi % 3 == 0)
       count++;
   }

    cout << "Броят на числата е " << count << endl;

   return 0;
}

int main8() {
    int n;
    cout << "n = "; cin >> n;
    assert(n >= 0);
    long long f = 1;
    /*
    for(int i = 1 ; i <= n ; i++)
        f *= i;
    */
    int i = 1;
    while (i <= n)
        f *= i++;
    // i > n
    cout << n << "! = " << f << endl;
    return 0;
}

int main9() {
    double x, sum = 0;
    int count = 0;
    while(cin >> x) {
        sum += x;
        count++;
    }
    // !cin, т.е. не сме въвели число
    if (count == 0)
        cout << "Не са въведени числа!\n";
    else
        cout << "Средното аритметично на числата е " << sum / count << endl;
    return 0;
}

int main10() {
   double x, eps;
   cout << "x = ";   cin >> x;
   cout << "eps = "; cin >> eps;
   long double s = 1, y = 1, i = 1;
   // y == a0 == 1
   // s == a0 == 1
   while(fabs(y) >= eps) {
      // s == сумата на всички от a0 до a(i-1) включително
      // y == a(i-1)
      (y *= x) /= i++;
      // y == ai
      s += y;
      // s == сумата на всички до a0 до ai включително
   }
   // |y| < eps
   cout << "exp(x) = " << exp(x) << endl;
   cout << "s      = " << s << endl;
   return 0;
}

int main11() {
    // число е просто <-> точно два делителя (1 и n)
    int n;
    cout << "n = "; cin >> n;
    /*
    int count = 0;
    for (int i = 1; i <= n; i++)
      if (n % i == 0)
        count++;
    cout << n;
    if (count != 2)
      cout << " НЕ";
    cout << " е просто\n";
    */
    // число НЕ е просто <-> има поне един делител между 2 и n-1 и n != 1
    bool hasDivisor = false;
    /*
    for(int i = 2; i < n; i++)
        if (n % i == 0) {
            hasDivisor = true; 
            break;               // !!!!!
        }
    */
    /*
    int i = 2;
    while (i < n && !hasDivisor) {
        if (n % i == 0)
            hasDivisor = true;
        i++;
    }
    cout << n;
    if (hasDivisor)
      cout << " НЕ";
    cout << " е просто\n";
    */
    int i = 2;
    // !(n % i == 0 || i == n)  <-->  n % i != 0 && i < n
    while (i < n && n % i != 0)
        i++;
    // намерили сме делител от 2 до n-1 <-> НЕ е просто
    // n % i == 0
    // или
    // сме разгледали всички възможни числа от 2 до n-1 и нито един от тях не е делител <-> е просто или е 1
    // i == n
    // n % i == 0 || i == n
    cout << n;
//    if (n % i == 0) !!!
    if (i < n || n <= 1) // това условие не се е нарушило, следователно се е нарушило другото
      cout << " НЕ";
    cout << " е просто\n";
    return 0;
}

int main12() {
    int n;
    cout << "n = "; cin >> n;
    for(int i = 1; i <= n; i++) {
        // извеждаме i-ти ред на пирамидата
        for(int j = 1; j <= i; j++)
            // извежда j-тото число на i-тия ред на пирамидата
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}

int main13() {

    for(int l = 0; l <= 6; l++)
        // l <= r <= 6
        for(int r = l; r <= 6; r++)
            cout << l << '|' << r << endl;
    return 0;
}

int main() {
    unsigned n, origNumber;
    cout << "n = "; cin >> n;
    origNumber = n;
    // bool foundRepeating = false;
    // int rest = n; // !!!
    int rest = 0;
    while(n >= 10 && rest == 0) {
        int d = n % 10; // d е последната цифра на n
        // искаме да сравним d с останалите цифри на n
        // среща ли се d в останалите цифри на n?
        rest = n /= 10;
        while(rest > 0 && rest % 10 != d)
            rest /= 10;
        // добър вариант: ДА: rest % 10 == d
        // лош вариант:   НЕ: rest == 0 прегледали сме всички цифри в rest и нито една от тях не е d
        // X || Y  -- излизаме
        // !(X || Y) -- оставаме -- !X && !Y
        // foundRepeating = rest % 10 == d; !!!
        // вместо ДА да напишем !НЕ
        // foundRepeating = rest > 0;
    }
    // добър вариант: ДА: rest > 0  вместо foundRepeating
    // лош вариант:   НЕ: n < 10
    cout << "В числото " << origNumber << (rest > 0 ? " има" : " няма") << " повтарящи се цифри.\n";
}
