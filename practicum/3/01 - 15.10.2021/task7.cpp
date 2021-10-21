#include <iostream>

using namespace std;

int main() {
    double x, y;
    cin >> x >> y;

    bool inRectangle = x >= -8 && x <= 3 && y >= -2 && y <= 1;
    bool inCircle =
        y >= 1 && (x - 2.5) * (x - 2.5) + (y - 1) * (y - 1) <= 5.5 * 5.5;

    bool inFigure = inRectangle || inCircle;

    return 0;
}