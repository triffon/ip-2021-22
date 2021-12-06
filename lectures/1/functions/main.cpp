#include <iostream>
using namespace std;

#include "functions.h"

int main() {

    // въвеждане на координатите
    cout << "Моля, въведете координати на върховете на триъгълника:" << endl;
    const int NPOINTS = 3;
    const int NCOORDS = 2;
    double coords[NPOINTS][NCOORDS];
    char coordNames[NCOORDS] = { 'x', 'y' };
    char pointNames[NPOINTS] = { 'A', 'B', 'C' };
    for(int i = 0; i < NPOINTS; i++)
        for(int j = 0; j < NCOORDS; j++)
            coords[i][j] = readCoordinate(pointNames[i], coordNames[j]);
    
    // пресмятане на лице
    double area = calculateTriangleArea(coords[0], coords[1], coords[2]);

    // извеждане на резултата
    printTriangleArea(area);

    return 0;
}
