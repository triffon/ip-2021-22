#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter n: "; cin >> n;
    int startStart = n - 1;
    int starEnd = n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < startStart; j++) {
            cout << " ";
        }
        for (int j = startStart; j <= starEnd; j++) {
            if ((j - startStart) % 2 == 0) {
                cout << "*";

            }
            else {
                cout << " ";
            }
        }
        for (int j = starEnd; j <= n; j++) {
            cout << " ";
        }
        starEnd += 1;
        startStart -= 1;
        cout << endl;
    }
    startStart += 2;
    starEnd -= 2;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < startStart; j++) {
            cout << " ";
        }
        for (int j = startStart; j <= starEnd; j++) {
            if ((j - startStart) % 2 == 0) {
                cout << "*";

            }
            else {
                cout << " ";
            }
        }
        for (int j = starEnd; j <= n; j++) {
            cout << " ";
        }
        starEnd -= 1;
        startStart += 1;
        cout << endl;
    }
}
