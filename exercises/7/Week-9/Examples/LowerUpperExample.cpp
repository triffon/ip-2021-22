/*
    Problem: Write a program that reads a string S from STDIN (0 < streln(S) < 1024).
             At the end of the program write on STDOUT S with all lowercase letters
             converted to uppercase & vice versa.
*/

#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;


void changeCase(char &c) {
    if ('a' <= c && c <= 'z') {
        c = 'A' + (c - 'a');
        return;
    }

    if ('A' <= c && c <= 'Z') {
        c = 'a' + (c - 'A');
        return;
    }
}

void switchCase(char *str) {
    for(int i = 0; str[i] != '\0'; ++i) {
        changeCase(str[i]);
    }
}

int main() {
    char s[1024];

    cout << "S: ";
    cin.getline(s, 1024);

    switchCase(s);

    cout << s << endl;

    return 0;
}