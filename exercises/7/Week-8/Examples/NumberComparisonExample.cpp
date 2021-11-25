/*
    Problem: Write a program that reads two strings A and B (only numerical characters)
             from STDIN (0 < strlen(A),strlen(B) < 20) and writes on STDOUT the string
             that represents the bigger number.
*/

#include<iostream>
#include<string.h>

using namespace std;

bool isGreater(char a[], char b[]) {
    for(int i = 0; i < strlen(a) ; ++i) {
        if(a[i] != b[i]) {
            return b[i] == '\0' || a[i] > b[i];
        }
    }

    return false;
}

int main() {
    char a[20];
    char b[20];

    cout << "A: ";
    cin >> a;

    cout << "B: ";
    cin >> b;

    if (isGreater(a, b)) {
        cout << a << " is bigger than " << b << endl;
    } else if(isGreater(b, a)) {
        cout << b << " is bigger than " << a << endl;
    } else {
        cout << a << " is equal to " << b << endl;
    }

    return 0;
}