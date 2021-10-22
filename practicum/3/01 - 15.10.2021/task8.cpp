#include <iostream>

using namespace std;

int main() {
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double x4, y4;
    double x5, y5;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    cin >> x4 >> y4;
    cin >> x5 >> y5;

    double minX = min(x1, x2);
    minX = min(minX, x3);
    minX = min(minX, x4);
    minX = min(minX, x5);

    double maxX = max(x1, x2);
    maxX = max(maxX, x3);
    maxX = max(maxX, x4);
    maxX = max(maxX, x5);

    double minY = min(y1, y2);
    minY = min(minY, y3);
    minY = min(minY, y4);
    minY = min(minY, y5);

    double maxY = max(y1, y2);
    maxY = max(maxY, y3);
    maxY = max(maxY, y4);
    maxY = max(maxY, y5);

    double area = (maxX - minX) * (maxY - minY);
    cout << area << endl;

    return 0;
}