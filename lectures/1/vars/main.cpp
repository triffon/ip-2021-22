#include <iostream>
#include <cmath>
using namespace std;

int main(int, char**) {
    const float STEP = 0.31; // 0.25; // 0.31;
    const float EPS = 1e-6; // 0.000001
    float x = STEP;
    x = x + STEP;
    x = x + STEP;
    x = x + STEP;
    x = x + STEP;
    if (fabs(x - 1.55) < EPS) {
        cout << "Да!" << endl;
    } else {
        cout << sizeof(x) << endl;
        cout.precision(30);
        cout << "Не! x = " << x << endl;
    }

    int y = 5;
    cout << x + y << endl;
    char c = 'C';
    int code = c;
    cout << "Кодът на " << c << " е " << code << endl;
    y = x;
    cout << "y = " << y << endl;
    cout << 5 / 2 << endl;
    cout << 5. / 2 << endl;
    cout << 5e0 / 2 << endl;
    cout << (float)5 / 2 << endl;
    y = -2;
    unsigned z = y;
    cout << z << endl;
    cout << (2 * 3 + 5) << ' ' << 5 + 2 * 3 << endl;
    // !!! (cout << 2) < 3;
    cout << (2 < 3) << endl;
    // !!! (cout << (2 < 3)() && ((3 < 4) << endl);
    cout << (2 < 3 && 3 < 4) << endl;
}
