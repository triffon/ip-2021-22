/*
    1. strlen(s1)     - Returns the length of string s1.
    2. strcpy(s1, s2) - Copies string s2 into string s1.
    3. strcat(s1, s2) - Concatenates string s2 onto the end of string s1.
    4. strstr(s1, s2) - Returns a pointer to the first occurrence of string s2 in string s1.
    5. strchr(s1, ch) - Returns a pointer to the first occurrence of character ch in string s1.
    6. strcmp(s1, s2) - Returns 0 if s1 and s2 are the same; less than 0 if s1<s2; greater than 0 if s1>s2.
*/

#include<iostream>

using namespace std;

int strlen(char *str) {
    int i = 0;
 
    for(; str[i] != '\0'; i++) {}

    return i;
}

void strcat(char *destination, char *target) {
    for(int i = 0, length = strlen(destination); i <= strlen(target); ++i) {
        destination[i + length] = target[i];
    }
}

void strcpy(char *destination, char *target) {
    for(int i = 0; i <= strlen(target); ++i) {
        destination[i] = target[i];
    }
}

char* strchr(char *str, char c) {
    for(int i = 0; i < strlen(str); ++i) {
        if(str[i] == c) {
            return str + i;
        }
    }

    return NULL;
}

int strcmp(char *first, char *second) {
    int i = 0;

    for(; first[i] != '\0' && second[i] != '\0' ; i++) {
        if(first[i] != second[i]) {
            return first[i] < second[i] ? -1 : 1;
        }
    }

    return first[i] == second[i] ? 0 : first[i] == '\0' ? -1 : 1;
}

char* strstr(char *str, char *candidate) {
    for(int i = 0; i <= strlen(str) - strlen(candidate); ++i) {
        for(int j = 0; j <= strlen(candidate); ++j) {
            if(candidate[j] == '\0') {
                return str + i;
            }

            if(str[i + j] != candidate[j]) {
                break;
            }
        }
    }

    return NULL;
}

int main() {
    char c = 'a', *str_1 = "bacd", *str_2= "ac", bufer[1025] = "";

    cout << "strlen(\"" << str_1 << "\") is " << strlen(str_1) << endl;
    cout << "strchr(\"" << str_1 << "\", \'" << c <<"\') is " << strchr(str_1, c) << endl;
    cout << "strstr(\"" << str_1 << "\", \"" << str_2 <<"\") is " << strstr(str_1, str_2) << endl;
    cout << "strcmp(\"" << str_1 << "\", \"" << str_2 <<"\") is " << strcmp(str_1, str_2) << endl;

    strcpy(bufer, str_1);
    strcat(bufer, str_2);
    cout << "strcat(\"" << str_1 << "\", \"" << str_2 <<"\") is " << bufer << endl;

    strcpy(bufer, str_1);
    strcpy(bufer, str_2);
    cout << "strcpy(\"" << str_1 << "\", \"" << str_2 <<"\") is " << bufer << endl;

    return 0;
}