/*
    Problem: Write a program that reads a string S from STDIN (0 < streln(S) < 1024).
             At the end of the program write on STDOUT S with all non-alphabetical
             characters removed.
*/

#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;


bool isAlhpabetical(char &c) {
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void prune(char *str) {
    for(int i = 0, j = 0, length = strlen(str); i <= length; i++) {
        if(isAlhpabetical(str[i]) || str[i] == '\0') {
            str[j] = str[i];
            j = j + 1; 
        }
    }
}

int main() {
    char s[1024];

    cout << "S: ";
    cin.getline(s, 1024);

    prune(s);

    cout << s << endl;

    return 0;
}