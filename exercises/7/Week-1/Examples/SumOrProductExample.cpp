#include <iostream>

using namespace std;

int calculateSum(int number) {
    int result = 0;

    for (int current = 1; current <= number; current++) {
        result += current;
    }

    return result;
}

int calculateProduct(int number) {
    int result = 1;

    for (int current = 1; current <= number; current++) {
        result *= current;
    }

    return result;
}

int main() {
    int n;
    char sumChoice, productChoice;

    cout << "N: ";
    cin >> n;

    cout << endl << "Calculate sum?[Y/N]: ";
    cin >> sumChoice;

    cout << endl << "Calculate product?[Y/N]: ";
    cin >> productChoice;

    if (sumChoice == 'Y' || sumChoice == 'y') {
        cout << endl << "Sum: " << calculateSum(n);
    }

    if (productChoice == 'Y' || productChoice == 'y') {
        cout << endl << "Product: " << calculateProduct(n);
    }

    return 0;
}
