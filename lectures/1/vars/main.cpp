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
}
