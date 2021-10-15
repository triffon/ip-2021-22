#include<iostream>

using namespace std;

int main() {
    int counter = 0;

    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int k = 1; k <= 4; ++k) {
                if ( i != j && i != k && j != k) {
                    counter++;
                    cout << i << j << k << endl;
                }
            }
        }
    }

    cout << "Total: " << counter << endl;
}