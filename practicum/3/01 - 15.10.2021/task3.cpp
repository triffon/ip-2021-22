#include <iostream>

using namespace std;

/*
Има 5 случая (с еднаквите букви са означени еднакви числа):
A A A -> този случай отговаря на условието
A A B -> този случай отговаря на условието
A B A -> този случай отговаря на условието
B A A -> този случай отговаря на условието
A B C -> този случай НЕ отговаря на условието

Понеже има един случай, който не отговаря на условието,
трябва да се напише булев израз, който е истина, само когато
не сме в третия случай.
*/

int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    bool oneNumberWithOddCount =
        !(num1 != num2 && num1 != num3 && num2 != num3);

    // друг вариант е
    oneNumberWithOddCount = num1 == num2 || num1 == num3 || num2 == num3;

    cout << oneNumberWithOddCount << endl;

    return 0;
}