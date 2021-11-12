/*
    Problem: Write a program that reads a number N from STDIN (N between 5 and 50)
             and then subsequently reads N numbers from STDIN. At the end of the
             program write on STDOUT whether the numbers form a symmetrical
             sequence - sequence is the same when read left to right and right to left.
*/

#include<iostream>
#include<algorithm>
#include <limits.h>

using namespace std;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

void readArray(string name, int elements[], int length) {
   for(int i = 0; i < length; ++i) {
       elements[i] = readVariable(name + "[" + to_string(i) + "]", INT_MIN, INT_MAX);
   }
}

bool isSymmetrical(int elements[], int length) {
    for(int i = 0, j = length-1; i < j; ++i,--j) {
        if(elements[i] != elements[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    int elements[100];
    int n = readVariable("N", 5, 50);

    readArray("element", elements, n);

    cout << "Symmetrical: " << boolalpha << isSymmetrical(elements, n) << endl;

    return 0;
}