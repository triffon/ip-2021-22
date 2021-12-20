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

int** readDynamicMatrix(unsigned m, unsigned n) {
    int** matrix = new int*[m];
    for(int i = 0; i < m; i++) {
        matrix[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> matrix[i][j]; // <-> *(*(matrix + i) + j)
        }
    }
    return matrix;
}

void printDynamicMatrix(int **a, unsigned m, unsigned n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
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

void testMatrix() {
    int** matrix = readDynamicMatrix(2, 3);
    printDynamicMatrix(matrix, 2, 3);
}

int main(int, char**) {
    //for(int i = 0; i < 100000; i++)
        //calculateAverage();
    testMatrix();
}
