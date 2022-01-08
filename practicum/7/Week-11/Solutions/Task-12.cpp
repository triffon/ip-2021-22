#include <iostream>

bool isPrime(int number) {
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimeElemsAbove(int** matrix, int n)
{
    int counter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPrime(matrix[i][j])) {
                counter++;
            }
        }
    }
}

int main()
{
    //Test it.


    return 0;
}