/*
    Problem: Subsequence of a given sequence S is a sequence that is created by
             deleting zero or more subsequent elements in the begining and/or end
             of S (e.g. abcde -> abcd, bcde). Rotation of a given sequence S is a
             sequence that is created by moving zero or more elements of S from
             its begining to its end (e.g abcde -> cdeab). Write a program that
             reads two numbers A and B (0 < B <= A < 1024) and then subsequently
             reads two sequences SA with length A and SB with length B from STDIN
             and writes on STDOUT whether a rotation of SB exists that is a
             subsequence of SA and if so - the rotation itself as well as the start
             and end indices of it in SA (if no such rotation exist - an error
             message shall be printed).
*/

#include<iostream>

using namespace std;

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

char readVariable(string variableName, char minValue, char maxValue) {
    char variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

void readArray(string name, int n, char elements[]) {
   for(int i = 0; i < n; ++i) {
       elements[i] = readVariable(name + "[" + to_string(i) + "]", 'a', 'z');
   }
}

bool isSubsequence(char c[], int cLength, int cStart, char s[], int sLength, int sStart) {
    for(int i = 0; i < cLength; ++i) {
        if((i + sStart) >= sLength || c[(i + cStart) % cLength] != s[i + sStart]) {
            return false;
        }
    }

    return true;
}

void printMessageFound(char sequence[], int length, int startAt, int deleteStart, int deleteEnd) {
    cout << "Rotation '";
    for(int i = 0; i < length; ++i) {
        cout << sequence[(i + startAt) % length];
    }
    cout << "' found after deleting " << deleteStart << " characters from the start and " << deleteEnd << " characters from the end." << endl; 
}

int main() {
    char sa[1024];
    char sb[1024];
    int a = readVariable("A", 1, 1024);
    int b = readVariable("B", 1, a);

    readArray("SA", a, sa);
    readArray("SB", b, sb);


    for(int i = 0; i < b; ++i) {
        for(int j = 0; j < a; ++j) {
            if(isSubsequence(sb, b, i, sa, a, j)) {
                printMessageFound(sb, b, i, j, a - b - j);
                return 0;
            }
        }
    }

    cout << "No rotation found!" << endl;

    return 0;
}