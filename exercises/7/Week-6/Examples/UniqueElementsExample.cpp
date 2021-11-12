/*
    Problem: Write a program that reads a number N STDIN (N between 5 and 50) and then
             subsequently reads N numbers from STDIN. At the end of the program write
             on STDOUT the unique numbers amongst the once read from STDIN.
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

int firstIndexOf(int element, int elements[], int length) {
   for(int i = 0; i < length; ++i) {
       if (elements[i] == element) {
           return i;
       }
   }

   return -1;
}

void printUniqueElements(int elements[], int length) {
    for(int i = 0; i < length; ++i) {
        if(firstIndexOf(elements[i], elements, length) == i) {
            cout << elements[i] << " ";
        }
    }

    cout << endl;
}

int main() {
    int elements[50];
    int n = readVariable("N", 5, 50);

    readArray("elements", elements, n);
    printUniqueElements(elements, n);

    return 0;
}