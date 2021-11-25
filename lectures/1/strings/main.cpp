#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

void overflowExample() {
    const int MAX_WORD = 8;
    char s2[] = "This is a very long string before word";
    char word[MAX_WORD] = { 'H', 'e', 'l', 'l', 'o', ' ', 'H', 'i'};
    char password[] = "This is a very long string after word";
    // read overflow
    cout << word << endl;         // !!!
    cout << strlen(word) << endl; // !!!

    // write overflow
    // cin >> word; // !!!
    cin.getline(word, MAX_WORD);
    cout << word << endl;
    cout << password << endl;
    cout << s2 << endl;
}

int mystrlen(char s[]) {
    int count = 0;
    /*
    !!!
    for(int i = 0; i < MAX; i++)
        if (s[i] != '\0')
            count++;
    */
    /* !!!
    for(int i = 0; i < MAX; i++)
        if (s[i] == '\0')
            return i;
    */
    while(s[count] != '\0') //  0 00 0x0 0.0 false
        count++;
    // while(s[count++]);

    // s[count] == '\0'
    return count;
}

void stringExamples() {
    const int MAX = 100;
    char s[MAX], s2[MAX];
    cout << "Моля, въведете низ: ";
    cin.getline(s, MAX);
    cout << "Дължината на низа е " << strlen(s) << endl;
    cout << "Моля, въведете втори низ: ";
    cin.getline(s2, MAX);
    cout << "s = " << s << endl;
    cout << "s2 = " << s2 << endl;
    /*
    if (strcmp(s, s2) <= 0) // s <= s2
    if (strcmp(s, s2) == 0) // s == s2
    if (strcmp(s, s2) >= 0) // s >= s2
    */

    // if (strcmp(s, s2)) // <-> strcmp(s, s2) != 0 <-> s != s2
    cout << "s <=> s2: " << strcmp(s, s2) << endl; 
    // cout << "s = " << strcpy(s, s2) << endl;
    cout << "s = " << strcat(s, s2) << endl; // !!! write overflow
    cout << "s2 = " << s2 << endl;
    cout << "s <=> s2: " << strcmp(s, s2) << endl; 
    // cout << strchr(s, 'e') << endl;
    if (strchr(s, 'e'))
        cout << "Символът 'e' се среща в " << s << endl;
    else
        cout << "Символът 'e' НЕ се среща в " << s << endl;
    if (strstr(s, "el"))
        cout << "Низът \"el\" се среща в " << s << endl;
    else
        cout << "Низът \"el\" НЕ се среща в " << s << endl;
}

void checkPalindrome() {
    const int MAX = 100;
    char s[MAX];
    cout << "Моля, въведете низ: ";
    cin.getline(s, MAX);
    size_t len = strlen(s);
    /*
    bool isPalindrome = true;
    for(int i = 0; i < len / 2 && isPalindrome; i++)
    //  if (s[i] == s[len - 1 - i]) count++;
        if (s[i] != s[len - 1 - i])
            isPalindrome = false;
    */

    int i = 0;
   // докато (не сме стигнали до средата и не сме видяли нарушение на условието за палиндром)
    while (i < len / 2 && s[i] == s[len - 1 - i])
        i++;
    // добър вариант: ДА: i == len / 2
    // лош вариант:   НЕ: s[i] != s[len - 1 - i]
    cout << "Низът \"" << s << '"';
    //if (!isPalindrome)
    if (i < len / 2) // НЕ <-> !ДА
        cout << " НЕ";
    cout << " е палиндром." << endl;
}

bool isdigit(char c) {
    return '0' <= c && c <= '9';
}

bool isop(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=';
}

int calculate(int left, char op, int right);

void calculator() {
    const int MAX = 100;
    char s[MAX];
    cout << "Моля, въведете низ: ";
    cin.getline(s, MAX);
    int i = 0, screen = 0, // се вижда на екрана на калкулатора
               memory = 0; // последния запомнен операнд
    char op = '+'; // все едно добавяме към 0, която е записана в паметта
    while(s[i] && op != '=') { // != '\0'
        if (isdigit(s[i]))
            screen = screen * 10 + (s[i] - '0');
        if (isop(s[i])) {
            // сега трябва да изпълним предишната операция
            // върху това, което е било в паметта (memory)
            // и това, което сега се вижда на екрана (screen)
            // и записваме резулата в паметта
            memory = calculate(memory, op, screen); // при първо изпълнение op == '+', memory == 0,
                                                    // т.е. screen = screen
            // след това запомняме новата операция
            op = s[i];
            // изчистваме екрана
            screen = 0;
        }

        i++;
    }
    cout << memory << endl;
}

int main(int, char**) {
    //overflowExample();
    //stringExamples();
    //checkPalindrome();
    calculator();
}


int calculate(int left, char op, int right) {
    switch(op) {
        case '+' : return left + right;
        case '-' : return left - right;
        case '*' : return left * right;
        case '/' : return right == 0 ? 0 : left / right;
        case '%' : return right == 0 ? 0 : left % right;
        default  : assert(isop(op)); return 0;
    }
}