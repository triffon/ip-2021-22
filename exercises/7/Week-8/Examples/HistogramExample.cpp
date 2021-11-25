/*
    Problem: Write a program that reads a string S (only lowercase latin characters)
             from STDIN (0 < streln(S) < 1024). At the end of the program write on
             STDOUT a histogram of S - the the number of times each lowercase latin
             character can be found in the string.
*/

#include<iostream>
#include<string.h>

using namespace std;

int main() {
    char s[1024];
    int histogram[26] = { 0 };

    cout << "S: ";
    cin >> s;

    for(int i = 0; i < strlen(s); ++i) {
        histogram[s[i] - 'a'] += 1;
    }

    for(int i = 0; i < 26; ++i) {
        cout << "Character '" << (char)('a' + i) << "' was found " << histogram[i] << " times" << endl; 
    }

    return 0;
}