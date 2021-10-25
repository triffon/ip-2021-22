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

int main() {
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