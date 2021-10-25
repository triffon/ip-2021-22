#include <iostream>
#include <cmath>
using namespace std;

int main1() {
    cout << "Hello, world!\n" << "It's me!" << endl;
    2 + 3;
    exp(sin(sqrt(15)));
    int x = 2;
    x = 5;
    x = 3.8;
    x = true;
    x = 2 < 3;
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

int main() {
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
    return 0;
}