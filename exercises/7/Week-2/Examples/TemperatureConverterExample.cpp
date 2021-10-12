#include<iostream>

using namespace std;

const int FIVEHUNDRED = 500;
const int MINUS_FIVEHUNDRED = -500;

char readScale() {
    char scale;

    do {
        cout << "S: ";
        cin >> scale;
    } while(scale != 'c' && scale != 'C' && scale != 'f' && scale != 'F');

    return scale;
}

int readVariable(string variableName, int minValue, int maxValue) {
    int variable;

    do {
        cout << variableName << ": ";
        cin >> variable;
    } while(variable < minValue || variable > maxValue);

    return variable;
}

int convertToCelsius(int t) {
    return ((t - 32)* 5) / 9;
}

int convertToFahrenheit(int t) {
    return ((t * 9) / 5) + 32;
}

int main() {
    int t = readVariable("T", MINUS_FIVEHUNDRED, FIVEHUNDRED);
    char s = readScale();

    if (s == 'c' || s == 'C') {
        cout << t << " degrees Celsius are ~" << convertToCelsius(t) << " degrees Fahrenheit" << endl; 
    } else {
        cout << t << " degrees Fahrenheit are ~" << convertToFahrenheit(t) << " degrees Celsius" << endl;
    }

    return 0;
}