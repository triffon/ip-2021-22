#include <iostream>
using namespace std;

#include "functions.h"

void readPoint(char pointName, double point[]) {
    const int NCOORDS = 2;
    char coordNames[NCOORDS] = { 'x', 'y' };
    for(int j = 0; j < NCOORDS; j++)
         point[j] = readCoordinate(pointName, coordNames[j]);
}

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
