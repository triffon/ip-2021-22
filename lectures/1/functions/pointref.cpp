#include "pointrefFunctions.hpp"

int* pointerFunction(int* px) {
    int y = *px + 1;
    //!!! return &y; // y е записан в стековата рамка, която изчезва!
    //!!! return &x; // x е записан в стековата рамка, която изчезва!
    int a[10] = { 0 };
    // return a; // a е записан в стековата рамка, която изчезва!
    return px;
}

int& refFunction(int* px, int& r) {
    int y = *px + 1;
    int z = r + 1;
    //!!! return y;    
    //!!! return z;
    // return r;
    return *px;
}