/* 
    Problem: Write a program that asks the user for a number n and gives them the possibility
             to choose between computing the sum and computing the product of 1,…,n.
*/

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
