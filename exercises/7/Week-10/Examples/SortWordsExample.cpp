/*
    Problem: Write a program that reads a string S from STDIN (0 < streln(S) < 128).
             At the end of the program write on STDOUT the words in S on (each word
             on a new line) and subsequently the words in S sorted in lexicographical
             order (each word on a new line).
*/

#include<iostream>
#include<string.h>

using namespace std;

void split(char words[65][128], char *str) {
    for(int i = 0, j = 0, k = 0, length = strlen(str); i < length; ++i) {
        if(str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\0')) { // found a word end
            strncpy(words[k++], str + j, i - j + 1); 
        }

        j = str[i] == ' ' ? i + 1 : j;
    }
}

void sort(char words[65][128]) {
    bool swapped = false;
    char buffer[128] = {'\0'};

    do {
        swapped = false;

        for (int i = 0; i < 64 && strlen(words[i+1]) > 0; ++i) {
            if(strcmp(words[i], words[i+1]) > 0) {
                swapped = true;
                strcpy(buffer, words[i]);
                strcpy(words[i], words[i+1]);
                strcpy(words[i+1], buffer);
            }
        }
    } while (swapped);
}

void print(char *prefix, char words[65][128]) {
    for(int i = 0; i < 65; ++i) {
        if(strlen(words[i]) == 0) {
            break;
        }

        cout << prefix << "[" << i << "]: " << words[i] << endl;
    }
}

int main() {
    char s[128];
    char words[65][128] = {{'\0'}};

    cout << "S: ";
    cin.getline(s, 128);

    split(words, s);
    print("words", words);

    sort(words);
    print("sorted_words", words);

    return 0;
}