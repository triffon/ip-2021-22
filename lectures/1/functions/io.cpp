#include <iostream>
using namespace std;

#include "functions.h"

// въвеждане на координата с име "coord" на точката с име "point"
double readCoordinate(char point, char coord) {
    cout << "Моля, въведете координата " << coord
         << " на точката " << point << ": ";
    double d;
    cin >> d;
    return d;
}

// извеждане на лицето
void printTriangleArea(double area) {
    cout << "Лицето на триъгълника е: " << area << endl;
}
