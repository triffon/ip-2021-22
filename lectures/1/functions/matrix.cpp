#include <iostream>
#include <cstring>
using namespace std;

#include "matrixFunctions.hpp"

// извежда матрицата a с размерност m x n в табличен вид
void printMatrix(int a[][MAX_COLUMNS], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
}

// въвежда от клавиатурата масив от низове и връща въведения брой низове
unsigned readStringArray(char (*arr)[MAX_LENGTH]) {
    unsigned count = 0;
    do
        // прочитаме низа arr[count]
        // cin >> arr[count]; // !!!!
        cin.getline(arr[count], MAX_LENGTH);
    while(arr[count++][0]);
    // не трябва да броим последния въведен низ, понеже е празен
    return count - 1;
}

// среща ли се низът s в масива от n низа arr 
bool stringInArray(char (*arr)[MAX_LENGTH], unsigned n, char const* s) {
    int i = 0;
    while (i < n && strcmp(s, arr[i]))
        i++;
    return i < n;
}