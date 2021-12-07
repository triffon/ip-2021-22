#include <iostream>
using namespace std;

#include "arrayFunctions.hpp"

// въвеждане на масив a от цели числа
// връща броя прочетени елементи
int readArray(int a[]) {
    int n;
    cout << "Въведете брой елементи: ";cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Въведете a[" << i << "] = ";
        cin >> a[i];
    }
    return n;
}

// извеждане на масив a от n цели числа
void printArray(int* a, int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

// търси дали елементът x се среща в масива a с дължина n
bool findInArray(int a[], int n, int x) {
    int i = 0;
    while (i < n && a[i] != x)
        i++;
    return i < n;
}

void findMinMaxArray(int a[], int n, int& min, int& max){
    // не можем да разчитаме, че min и max са инициализирани!!!
    min = max = a[0];
    for(int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
}