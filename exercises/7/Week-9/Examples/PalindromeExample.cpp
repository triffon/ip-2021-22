/*
    Problem: Write a program that reads a string S from STDIN (0 < streln(S) < 1024).
             At the end of the program write on STDOUT wheter S is a palindrome.
*/

#include<iostream>
#include<string.h>

using namespace std;

bool isPalindrome(char *str) {
    for(int i = 0, length = strlen(str); i < length / 2; ++i) {
        if(str[i] != str[length - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    char s[1024];

    cout << "S: ";
    cin >> s;

    cout << (isPalindrome(s) ? "True" : "False") << endl;

    return 0;
}