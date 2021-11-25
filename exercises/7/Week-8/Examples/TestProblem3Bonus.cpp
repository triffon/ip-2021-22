/*
    Problem: Rotation of a given sequence S is a sequence that is created by
             moving zero or more elements of S from its begining to its end
             (e.g abcde -> cdeab). Write a program that reads two numbers A
             and B (0 < B <= A < 1024) and then subsequently reads two
             sequences SA with length A and SB with length B from STDIN and
             writes on STDOUT whether a rotation of SB exists that is equal 
             to a sequence created out of SA after the deletion of some of
             its symbols (if possible - write on STDOUT the rotation itself
             as well as the positions at which symbols need to be deleted).
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

bool isContained(char c[], int cLength, int cStart, char s[], int sLength) {
    for(int i = 0, j = 0; i < cLength; j++) {
        if(j == sLength) {
            return false;
        }

        i += c[(i + cStart) % cLength] == s[j];
    }

    return true;
}

void printMessageFound(char sequence[], int length, int startAt, char other[], int otherLength) {
    cout << "Rotation '";

    for(int i = 0; i < length; ++i) {
        cout << sequence[(i + startAt) % length];
    }

    cout << "' found after deleting symbols at positions ";

    for(int i = 0, j = 0; j < otherLength; j++) {
        if(i < length && sequence[(i + startAt) % length] == other[j]) {
            i = i + 1;
            continue;
        }

        cout << j << " ";
    }

    cout << endl;
}

int main() {
    char sa[1024];
    char sb[1024];
    int a = readVariable("A", 1, 1024);
    int b = readVariable("B", 1, a);

    readArray("SA", a, sa);
    readArray("SB", b, sb);


    for(int i = 0; i < b; ++i) {
        if(isContained(sb, b, i, sa, a)) {
            printMessageFound(sb, b, i, sa, a);
            return 0;
        }
    }

    cout << "No rotation found!" << endl;

    return 0;
}