#include <iostream>
using namespace std;

unsigned readSize() {
    unsigned n;
    //cout << "Моля, въведете брой на числата: ";
    cin >> n;
    // n = 100000;
    return n;
}

int* readArray(unsigned n) {
    int* a = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "a[" << i << "]  = ";
        cin >> a[i];
        a[i] = i;
    }
    return a;
}

double findAverage(int a[], unsigned n) {
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
}

void calculateAverage() {
    unsigned n = readSize();
    int* array = readArray(n);
    cout << "Средното аритметично на редицата е " << findAverage(array, n) << endl;
    delete[] array;
}

int main(int, char**) {
    //for(int i = 0; i < 100000; i++)
        calculateAverage();
}
