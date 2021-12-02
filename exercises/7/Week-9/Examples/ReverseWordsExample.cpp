/*
    Problem: Write a program that reads a string S from STDIN (0 < streln(S) < 1024).
             At the end of the program write on STDOUT all words in S in a reverse order.
*/

#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

void reverse(char *start, char *end) {
    for(; start < end; start++, end--) {
        swap(*start, *end);
    }
}

void reverseWords(char *str) {
    reverse(str, str + strlen(str) - 1);

    for(int i = 0, j = 0, length = strlen(str); i < length - 1; ++i) {
        if(str[i] != ' ' && str[i+1] == ' ') { // found a word end
            reverse(str + j, str + i);
        }

        j = str[i] == ' ' ? i + 1 : j;
    }

}

int main() {
    char s[1024];

    cout << "S: ";
    cin.getline(s, 1024);

    reverseWords(s);

    cout << "Reversed: <" << s << ">" << endl;

    return 0;
}