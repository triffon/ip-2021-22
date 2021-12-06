#include "functions.h"
#include <cmath>

// пресмятане на лице на триъгълник по три точки
double calculateTriangleArea(double A[1], double B[1], double C[1]) {
    // пресмятане на страните
    double a = calculateDistance(B, C);
    double b = calculateDistance(A, C);
    double c = calculateDistance(A, B);

    // пресмятане на лицето с формулата на Хирон
    return heron(a, b, c);
}

// пресмятане на полупериметъра
double calculateHalfPerimeter(double a, double b, double c) {
    // !!! a += 5;
    return (a + b + c) / 2;
}

// пресмятане на лице на триъгълник по три страни
double heron(double a, double b, double c) {
    double p = calculateHalfPerimeter(a, b, c);
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
