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

int** createDynamicMatrix(unsigned m, unsigned n) {
    int** matrix = new int*[m];
    for(int i = 0; i < m; i++)
        matrix[i] = new int[n];
    return matrix;
}

int** readDynamicMatrix(int** matrix, unsigned m, unsigned n) {
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> matrix[i][j]; // <-> *(*(matrix + i) + j)
        }
    return matrix;
}

int** readDynamicMatrix(unsigned m, unsigned n) {
    return readDynamicMatrix(createDynamicMatrix(m, n), m, n);
}

void printDynamicMatrix(int **a, unsigned m, unsigned n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
}

void deleteDynamicMatrix(int **a, unsigned m) {
    for(int i = 0; i < m; i++)
        delete[] a[i];
    delete[] a;
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
    deleteDynamicMatrix(matrix, 2);
}

int** transposeMatrix(int **matrix, unsigned m, unsigned n) {
    int ** newmatrix = createDynamicMatrix(n, m);
    for(int j = 0; j < n; j++)   
        for(int i = 0; i < m; i++)
            newmatrix[j][i] = matrix[i][j];
    // изтриваме старата матрица
    deleteDynamicMatrix(matrix, m);
    return newmatrix;
}

void testTranspose() {
    unsigned m, n;
    cout << "m = ";cin >> m;
    cout << "n = ";cin >> n;
    int ** matrix = readDynamicMatrix(m, n);
    printDynamicMatrix(matrix, m, n);
    matrix = transposeMatrix(matrix, m, n);
    printDynamicMatrix(matrix, n, m);
    deleteDynamicMatrix(matrix, n);
}

int main(int, char**) {
    //for(int i = 0; i < 100000; i++)
        //calculateAverage();
    // testMatrix();
    testTranspose();
}
