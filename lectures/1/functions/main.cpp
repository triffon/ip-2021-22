#include <iostream>
using namespace std;

#include "functions.hpp"
#include "arrayFunctions.hpp"
#include "matrixFunctions.hpp"
#include "pointrefFunctions.hpp"

int triangleArea() {

    // въвеждане на координатите
    cout << "Моля, въведете координати на върховете на триъгълника:" << endl;
    const int NPOINTS = 3;
    const int NCOORDS = 2;
    double coords[NPOINTS][NCOORDS];
    char pointNames[NPOINTS] = { 'A', 'B', 'C' };
    for(int i = 0; i < NPOINTS; i++)
        readPoint(pointNames[i], coords[i]);
/*
        for(int j = 0; j < NCOORDS; j++)
            coords[i][j] = readCoordinate(pointNames[i], coordNames[j]);
        */
    
    // пресмятане на лице
    double area = calculateTriangleArea(coords[0], coords[1], coords[2]);

    // извеждане на резултата
    printTriangleArea(area);

    return 0;
}

int x = 2;

void f(int& zzz) {
    static int y = x; // инициализира се при първото извикване на f
    cout << "f: " << x++ << ' ' << y++ << '\t' << zzz++ << endl;
}

void g(int z) {
    f(z);
    cout << "g: " << x++ << '\t' << z++ << endl;
    f(z);
}

void sharingTest() {
    g(2);
}

void swapVars(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void swapVars(double& x, double& y) {
    double tmp = y;
    y = x;
    x = tmp;
}

/* !!!
int swapVars(double& x, double& y) {
    double tmp = y;
    y = x;
    x = tmp;
    return x;
} */

void fakeSwap(int x, int y) {
    cout << "fakeSwap: " << x << ' ' << y << endl;
}

void swapTest() {
    int a = 3, b = 5;
    swapVars(a, b);
    cout << a << ' ' << b << endl;

    double x = 1.2, y = 3.4;
    swapVars(x, y);
    // fakeSwap(x, y);
    cout << x << ' ' << y << endl;
}

void arrayTest() {
    const int MAX = 100;
    int array[MAX] = { 0 };
    int n = readArray(array);
    cout << printArray(array, n)[3] << endl;

    int x;
    cout << "x = "; cin >> x;
    cout << "Числото " << x;
    if (!findInArray(array, n, x))
        cout << " НЕ";
    cout << " се среща в масива" << endl;

    int min, max;
    findMinMaxArray(array, n, min, max);
    cout << "Най-малкият  елемент на масива е " << min << endl;
    cout << "Най-големият елемент на масива е " << max << endl;
}

void matrixTest() {
    int a[][MAX_COLUMNS] = { {1, 2, 3}, {4, 5, 6} };
    printMatrix(a, 2, 3);

    const int MAX_STRINGS = 10;
    char stringArray[MAX_STRINGS][MAX_LENGTH];
    unsigned n = readStringArray(stringArray);
    for(int i = 0; i < n; i++)
        cout << stringArray[i] << endl;

    char s[MAX_LENGTH];
    cout << "Моля, въведете дума за търсене: ";
    cin.getline(s, MAX_LENGTH);
    cout << "Думата " << s;
    if (!stringInArray(stringArray, n, s))
        cout << " НЕ";
    cout << " се среща в масива от низове." << endl;
}

void badPointerTest() {
    int x = 3;
    int* p = pointerFunction(&x);
    cout << *p << endl;
}

void badRefTest() {
    int x = 3;
    int& z = refFunction(&x, x);
    cout << z << endl;
    z = 10;
    cout << x << endl;
    refFunction(&x, x)++;
    cout << x << endl;
}

int main() {
    // triangleArea();
    // sharingTest();
    // swapTest();
    // arrayTest();
    // matrixTest();
    // badPointerTest();
    badRefTest();
}