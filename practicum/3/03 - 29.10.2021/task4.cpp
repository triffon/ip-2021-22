#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // double за да може да се извършва дробно деление
    double sumEven = 0, sumOdd = 0;

    while (n != 0) {
        int digit = n % 10;


        // if (digit % 2 == 0) {
        //     sumEven += digit;
        // } else {
        //     sumOdd += digit;
        // }

        // С тернарния оператор
        (digit % 2 == 0 ? sumEven : sumOdd) += digit;

        n /= 10;
    }

    cout << sumEven / sumOdd << endl;

    return 0;
}
