/*
    Problem: Write a program that prints all prime numbers between 1 and 1 000 000.
*/

#include <iostream>

using namespace std;

bool isPrime(int number) {
    for (int test = 2; test < number; ++test) {
        if (number % test == 0) {
            return false;
        }
    }

    return number > 0;
}

int main() {
    int count =0;
    for (int number = 1; number < 1000000; ++number) {
        if (isPrime(number)){
            count += 1;
            cout << "Prime Number:" << number << endl;        
        }
    }

    cout << "Total:" << count << endl;

    return 0;
}

