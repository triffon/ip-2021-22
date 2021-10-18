#include <iostream>
using namespace std;

int main(int, char**) {
    const float STEP =  0.25; // 0.31;
    float x = STEP;
    x = x + STEP;
    x = x + STEP;
    x = x + STEP;
    x = x + STEP;
    if (x == 1.25) {
        cout << "Да!" << endl;
    } else {
        cout << sizeof(x) << endl;
        cout.precision(30);
        cout << "Не! x = " << x << endl;
    }
}
