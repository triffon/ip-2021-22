#include "functions.hpp"
#include <cmath>

double square(double x) {
    return x * x;
}

// пресмятане на дължина на отсечка с два края
double calculateDistance(double P[], double Q[]) {
    return sqrt(square(P[0] - Q[0]) + square(P[1] - Q[1]));
}